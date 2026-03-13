#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("USAGE: parta FILEIN\n");
        return 1;
    }

    // Declare the buffer to use. Do NOT change!
    enum { BUFSIZE = 8 };
    char buffer[BUFSIZE];
    
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int space = 0;
    int other = 0;

    char* filepath = argv[1];

    FILE* fout = fopen(filepath, "r");
    if (fout == NULL) {
        printf("ERROR: %s not found\n", filepath);
        return 2;
    }

    while(fgets(buffer, sizeof(buffer), fout)) {
        for(int i = 0; buffer[i] != '\0'; i++) {
            char c = buffer[i];
            if(isupper((unsigned char)c)) {
                upper++;
            } else if(islower((unsigned char)c)) {
                lower++;
            } else if(isdigit((unsigned char)c)) {
                digit++;
            } else if(isspace((unsigned char)c)) {
                space++;
            } else {
                other++;
            }
        }
    }

    fclose(fout);
    printf("Upper,%d\n", upper);
    printf("Lower,%d\n", lower);
    printf("Number,%d\n", digit);
    printf("Space,%d\n", space);
    printf("Other,%d\n", other);
    return 0;
}
