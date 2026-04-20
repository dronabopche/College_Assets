#include <stdio.h>
#include <ctype.h>

// e: 12.70%, t: 9.06%, a: 8.17%, o: 7.51%
void top4change(int freq[], char subMap[]) {
    int max[4] = {-1, -1, -1, -1};
    int index[4] = {-1, -1, -1, -1};

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 4; j++) {
            if (freq[i] > max[j]) {
                for (int k = 3; k > j; k--) {
                    max[k] = max[k - 1];
                    index[k] = index[k - 1];
                }
                max[j] = freq[i];
                index[j] = i;
                break;
            }
        }
    }

    char mapTo[4] = {'e', 't', 'a', 'o'};

    // default mapping (identity)
    for (int i = 0; i < 26; i++) {
        subMap[i] = 'a' + i;
    }

    // apply top 4 mapping
    for (int i = 0; i < 4; i++) {
        if (index[i] != -1) {
            subMap[index[i]] = mapTo[i];
        }
    }
}

int main() {
    FILE *fin, *fout;
    int freq[26] = {0};
    char ch;
    char subMap[26];

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // count frequency
    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }

    fclose(fin);

    top4change(freq, subMap);

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if (fout == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // substitute
    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            fputc(subMap[ch - 'a'], fout);
        } else {
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);

    printf("Done. Output written to output.txt\n");

    return 0;
}