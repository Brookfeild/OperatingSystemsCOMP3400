#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

/*
* This program takes in command line arguments and prints the middle argument(s) using the echo command.
* If the number of arguments is odd, it prints the single middle argument.
* If the number of arguments is even, it prints the two middle arguments.
*/

int main(int argc, const char* argv[]) {
    if (argc <= 1) {
        printf("ERROR: No arguments\n");
        return 1;
    }

    int len = 0;
    while (len < argc) {
        len++;
    }

    int middle = len / 2.0;

    char oddeven;
    if (len % 2 == 0) {
        oddeven = 'E';
    } else {
        oddeven = 'O';
    }

    if (oddeven == 'O') {
        char* twomiddle[] = {"echo", (char *)argv[middle], (char *)argv[middle + 1], NULL};
        execv("/bin/echo", twomiddle);
    } else {
        char* onemiddle[] = {"echo", (char *)argv[middle], NULL};
        execv("/bin/echo", onemiddle);
    }
}
