#include <stdio.h>
#include <ctype.h>

#define SIZE 16

// 16x16 Playfair Matrix (All ASCII characters from 0-255)
unsigned char matrix[SIZE][SIZE];

// Initialize matrix
void initMatrix() {
    int k = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = k++;
        }
    }
}

// Find position of character in matrix
void findPosition(unsigned char ch, int *row, int *col) {
    *row = ch / SIZE;
    *col = ch % SIZE;
}

// Encrypt pair
void encryptPair(unsigned char a, unsigned char b,
                 unsigned char *ea, unsigned char *eb) {

    int r1, c1, r2, c2;

    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    // Same row
    if (r1 == r2) {
        *ea = matrix[r1][(c1 + 1) % SIZE];
        *eb = matrix[r2][(c2 + 1) % SIZE];
    }

    // Same column
    else if (c1 == c2) {
        *ea = matrix[(r1 + 1) % SIZE][c1];
        *eb = matrix[(r2 + 1) % SIZE][c2];
    }

    // Rectangle rule
    else {
        *ea = matrix[r1][c2];
        *eb = matrix[r2][c1];
    }
}

// Decrypt pair
void decryptPair(unsigned char a, unsigned char b,
                 unsigned char *da, unsigned char *db) {

    int r1, c1, r2, c2;

    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    // Same row
    if (r1 == r2) {
        *da = matrix[r1][(c1 + SIZE - 1) % SIZE];
        *db = matrix[r2][(c2 + SIZE - 1) % SIZE];
    }

    // Same column
    else if (c1 == c2) {
        *da = matrix[(r1 + SIZE - 1) % SIZE][c1];
        *db = matrix[(r2 + SIZE - 1) % SIZE][c2];
    }

    // Rectangle rule
    else {
        *da = matrix[r1][c2];
        *db = matrix[r2][c1];
    }
}

int main() {

    FILE *fin, *fout;
    unsigned char ch1, ch2;
    unsigned char out1, out2;

    initMatrix();

    fin = fopen("input.txt", "rb");
    fout = fopen("output.txt", "wb");

    if (!fin || !fout) {
        printf("File Error\n");
        return 1;
    }

    int mode;

    printf("1. Encrypt\n");
    printf("0. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &mode);

    while ((ch1 = fgetc(fin)) != EOF) {

        ch2 = fgetc(fin);

        // If odd number of bytes
        if (ch2 == EOF)
            ch2 = 'X';

        if (mode == 1) {
            encryptPair(ch1, ch2, &out1, &out2);
        } else {
            decryptPair(ch1, ch2, &out1, &out2);
        }

        fputc(out1, fout);
        fputc(out2, fout);
    }

    fclose(fin);
    fclose(fout);

    printf("Operation Completed\n");

    return 0;
}