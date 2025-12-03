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

    int frame[f];
    for (int i = 0; i < f; i++)
        frame[i] = -1;

    int faults = 0, index = 0;

    printf("\nFIFO Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;

        // check if page already in frame
        for (int j = 0; j < f; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) { // page fault
            frame[index] = page;
            index = (index + 1) % f;
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
