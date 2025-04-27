#include "Header.h"

int main() {
    int mainChoice;
    int Maxsize;
    CharQueue queue;
  //  initQueue(&queue, 10);
    do {
        printf("\nMain menu:\n");
        printf("1. Task 1: Work with Queue\n");
        printf("2. Task 2: Work with Dek\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf_s("%d", &mainChoice);
        getchar();

        if (mainChoice == 1 || mainChoice == 2) {
            printf("Enter max size: ");
            scanf_s("%d", &Maxsize);
            getchar();
            if (Maxsize <= 0) {
                printf("Capacity must be positive\n");
                continue;
            }
            initQueue(&queue, Maxsize);
        }

        switch (mainChoice) {
        case 1: WorkWithQueue(&queue); break;
        case 2: WorkWithDek(&queue); break;
        case 3: printf("Exiting...\n"); break;
        default: printf("Invalid choice\n");
        }
        if (mainChoice == 1 || mainChoice == 2) {
            freeQueue(&queue);
        }
    } while (mainChoice != 3);
}