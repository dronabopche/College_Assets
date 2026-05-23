#include <stdio.h>
#include <ctype.h>

void substitute_top4(FILE *fin) {
    FILE *fout;
    char ch;

    char top4_in_cipher[4] = {'y', 'q', 'p', 'm'}; //manually identified top 4 letters 
                                                   // so that we can recreate the key and decrypt the cipher text
    char top4_in_english[4] = {'e', 't', 'a', 'o'};

    rewind(fin);

    fout = fopen("decrypted_message.txt", "w");
    if (fout == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    while ((ch = fgetc(fin)) != EOF) {
        if (islower(ch)) {
            int replaced = 0;

            for (int i = 0; i < 4; i++) {
                if (ch == top4_in_cipher[i]) {
                    fputc(top4_in_english[i], fout);
                    replaced = 1;
                    break;
                }
            }

            if (!replaced) {
                fputc(ch, fout);
            }
        } else {
            fputc(ch, fout);
        }
    }

    fclose(fout);
    printf("Decryption (partial) written to output.txt\n");
}

int main() {
    FILE *fin;
    int freq[26] = {0};
    char ch;

    fin = fopen("encrypted_message.txt", "r");
    if (fin == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    //count freq
    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }

    //print freq
    for (int i = 0; i < 26; i++) {
        if (i == 13) { 
            printf("\n");
        }
        printf("%c: %d |", 'a' + i, freq[i]);
    }

    substitute_top4(fin);

    fclose(fin);
    return 0;
}