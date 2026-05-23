#include <stdio.h>
#include <ctype.h>

char pair[5][5] = {
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'K'},
    {'L', 'M', 'N', 'O', 'P'},
    {'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'X', 'Y', 'Z'}
};

// ENCRYPT (shift right)
char pair_encrypt(char ch) {
    ch = toupper(ch);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (pair[i][j] == ch) {
                return pair[i][(j + 1) % 5];  // shift right
            }
        }
    }
    return ch;
}

// DECRYPT (shift left)
char pair_decrypt(char ch) {
    ch = toupper(ch);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (pair[i][j] == ch) {
                return pair[i][(j + 4) % 5];  // shift left
            }
        }
    }
    return ch;
}

int main() {
    FILE *fin, *fout;
    char ch;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if (!fin || !fout) {
        printf("File error\n");
        return 1;
    }

    int mode = 1; // 1 = encrypt, 0 = decrypt

    while ((ch = fgetc(fin)) != EOF) {
        if (isalpha(ch)) {
            if (mode)
                fputc(pair_encrypt(ch), fout);
            else
                fputc(pair_decrypt(ch), fout);
        } else {
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);

    printf("Done.\n");
    return 0;
}