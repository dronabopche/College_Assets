#include <stdio.h>
#include <string.h>

char key[] = "KEY";

// ENCRYPT
unsigned char encrypt_char(unsigned char ch, int index) {
    unsigned char k = key[index % strlen(key)];
    return (unsigned char)((ch + k) % 256);
}

// DECRYPT
unsigned char decrypt_char(unsigned char ch, int index) {
    unsigned char k = key[index % strlen(key)];
    return (unsigned char)((ch - k + 256) % 256);
}

int main() {
    FILE *fin, *fout;
    unsigned char ch;

    fin = fopen("input.txt", "rb");
    fout = fopen("output.txt", "wb");

    if (!fin || !fout) {
        printf("File error\n");
        return 1;
    }

    int mode = 1; 
    int keyIndex = 0;

    while ((ch = fgetc(fin)) != EOF) {

        if (mode)
            fputc(encrypt_char(ch, keyIndex), fout);
        else
            fputc(decrypt_char(ch, keyIndex), fout);

        keyIndex++;
    }

    fclose(fin);
    fclose(fout);

    printf("Done.\n");
    return 0;
}