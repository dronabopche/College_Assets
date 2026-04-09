#include <stdio.h>
#include <ctype.h>

char curr[30] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
               'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
               'U', 'V', 'W', 'X', 'Y', 'Z'};

char key[30]  = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
                'X', 'C', 'V', 'B', 'N', 'M'};

char mono_encrypt(char ch) {
        for (int i = 0; i < 26; i++) {
            if (curr[i] == ch) {
                return key[i];
            }
        }
    return ch;
}

int main() {
    FILE *fin, *fout;
    char ch;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output file.\n");
        fclose(fin);
        return 1;
    }

    while ((ch = fgetc(fin)) != EOF) {
        fputc(mono_encrypt(ch), fout);
    }

    printf("Encryption completed.\n");

    fclose(fin);
    fclose(fout);

    return 0;
}