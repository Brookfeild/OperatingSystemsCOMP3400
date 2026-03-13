#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("USAGE: partc FILEIN\n");
        return 1;
    }

    char* const filein = (char *)argv[1];

    int pipefd[2];
    int pret = pipe(pipefd);
    if(pret) {
        perror("pipe");
        return 1;
    }
    
    int read_fd = pipefd[0];
    int write_fd = pipefd[1];

    int fret = fork();

    if(fret > 0) {
        //Parent
        close(read_fd);
        dup2(write_fd, STDOUT_FILENO);
        char *args[] = {"parta", filein, NULL};
        int eret = execv("/home/rickettst/a5/parta", args);
        if(eret == -1) {
            perror("execv failed");
        }
        close(write_fd);
    } else if(fret == 0) {
        //Child
        close(write_fd);
        dup2(read_fd, STDIN_FILENO);
        char *args[] = {"sort", "-t,", "-k2", "-n", NULL};
        int eret = execv("/usr/bin/sort", args);
        if(eret == -1) {
            perror("execv failed");
        }
        close(read_fd);
    } else {
        perror("Fork failed");
    }

    return 0;
}
