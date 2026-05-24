#include <stdio.h>
#include <ctype.h>
#include <string.h>

char key[] = "KEY";   // Vigenere key

// ENCRYPT
char encrypt_char(char ch, int index) {
    if (isupper(ch)) {
        return ((ch - 'A' + (toupper(key[index]) - 'A')) % 26) + 'A';
    }
    else if (islower(ch)) {
        return ((ch - 'a' + (toupper(key[index]) - 'A')) % 26) + 'a';
    }

    return ch;
}

// DECRYPT
char decrypt_char(char ch, int index) {
    if (isupper(ch)) {
        return ((ch - 'A' - (toupper(key[index]) - 'A') + 26) % 26) + 'A';
    }
    else if (islower(ch)) {
        return ((ch - 'a' - (toupper(key[index]) - 'A') + 26) % 26) + 'a';
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
    int keyIndex = 0;
    int keyLen = strlen(key);

    while ((ch = fgetc(fin)) != EOF) {

        if (isalpha(ch)) {

            if (mode)
                fputc(encrypt_char(ch, keyIndex), fout);
            else
                fputc(decrypt_char(ch, keyIndex), fout);

            keyIndex = (keyIndex + 1) % keyLen;
        }
        else {
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);

    printf("Done.\n");

    return 0;
}