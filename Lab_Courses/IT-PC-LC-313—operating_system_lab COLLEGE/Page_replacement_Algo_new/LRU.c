#include <stdio.h>

int main() {
    int n, f;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f], lastUsed[f];
    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        lastUsed[i] = -1;
    }

    int faults = 0, time = 0;

    printf("\nLRU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;

        // check if present
        for (int j = 0; j < f; j++) {
            if (frame[j] == page) {
                found = 1;
                lastUsed[j] = time++;
                break;
            }
        }

        if (!found) {
            int lruIndex = 0;
            for (int j = 1; j < f; j++) {
                if (frame[j] == -1) { lruIndex = j; break; }
                if (lastUsed[j] < lastUsed[lruIndex])
                    lruIndex = j;
            }

            frame[lruIndex] = page;
            lastUsed[lruIndex] = time++;
            faults++;
        }

        // print frames
        for (int j = 0; j < f; j++)
            (frame[j] == -1) ? printf("- ") : printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
