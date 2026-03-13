#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 3) {
        printf("USAGE: partb FILEIN FILEOUT\n");
        return 1;
    }

    char* filein = (char *)argv[1];
    char* fileout = (char *)argv[2];

    char* command[] = {"./parta", filein, NULL};

    pid_t pid = fork();

    if (pid == 0) {

        int fd = open(fileout, O_WRONLY | O_CREAT | O_TRUNC, 0770);
        if (fd < 0) {
            perror("open failed");
            return 1;
        }

        char* header = "Category,Count\n";
        write(fd, header, strlen(header));

        dup2(fd, STDOUT_FILENO);
        close(fd);

        char* command[] = {"./parta", filein, NULL};

        execv("./parta", command);

        perror("exec failed");
        return 1;
    }

    wait(NULL);
    return 0;
}
