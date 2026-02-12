#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/*
* This program takes in command line arguments and prints the middle argument(s) using the echo command.
* If the number of arguments is odd, it prints the single middle argument.
* If the number of arguments is even, it prints the two middle arguments.
*/

int main(int argc, const char* argv[]) {
    if(argc <= 1) {
        printf("ERROR: No arguments\n");
        return 1;
    }

    const char *input = argv[argc-1];
    int len = 0;

    for(int i = 1; i < argc; i++) {
        int j = 0;
        while (argv[i][j] != '\0') {
            len++;
            j++;
        }
        if (i < argc - 1) {
            len++;
        }
    }

    char capitalized[len + 1];
    int pos = 0;

    for (int i = 1; i < argc; i++){
        int j = 0;
        while (argv[i][j] != '\0') {
            char c = argv[i][j];
            if (c >= 'a' && c <= 'z') {
                c -= ('a' - 'A');
            }
            capitalized[pos++] = c;
            j++;
        }
        if (i < argc - 1) {
            capitalized[pos++] = ',';
        }
    }

    capitalized[pos] = '\0';

    printf("%s\n", capitalized);
    return 0;
}
