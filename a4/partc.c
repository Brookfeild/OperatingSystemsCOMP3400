#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/*
* This program takes in a word and a file location as command line arguments and uses the grep command to search for the word in the specified file.
* It prints whether the word was found or not found, and handles errors such as the file not existing or grep terminating unexpectedly.
*/  

int main(int argc, const char* argv[]) {
    if(argv[1] == NULL) {
        printf("ERROR: No arguments\n");
        return 1;
    }

    char* word = (char *)argv[1];
    char* location = (char *)argv[2];
    char* command[] = {"grep", "-s", "-q", word, location, NULL};

    int fret = fork();
    if (fret < 0) { 
        perror("fork error");
        return 1;
    }

    if (fret == 0) { 
        execv("/bin/grep", command);
    } 

    int wstatus;
    if (waitpid(fret, &wstatus, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(wstatus)) {
        int gexit = WEXITSTATUS(wstatus);

        switch (gexit) {
            case 0:
                printf("FOUND: %s\n", word);
                return 0;

            case 1:
                printf("NOT FOUND: %s\n", word);
                return 0;

            case 2:
                printf("ERROR: %s doesn't exist\n", location);
                return 2;

            default:
                printf("ERROR: %s doesn't exist (grep returned %d)\n", location, gexit);
                return 2;
        }
    } else {
        printf("ERROR: grep terminated unexpectedly\n");
        return 2;
    }

    return 0;
}
