#include "Header.h"

int main() {
    int Maxsize;
    printf("Enter queue capacity: ");
    scanf_s("%d", &Maxsize);

    if (Maxsize <= 0) {
        printf("Capacity must be positive\n");
        return 1;
    }

    CharQueue queue;
    initQueue(&queue, Maxsize);

    int choice;
    char input;

    do {
        printf("\nMenu:\n");
        printf("1. Insert (add character)\n");
        printf("2. Remove (remove character)\n");
        printf("3. Print queue\n");
        printf("4. Get queue size\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf_s("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printf("Enter character to enqueue: ");
            scanf_s("%c", &input, 1);
            insert(&queue, input);
            break;
        case 2:
            input = removeQueue(&queue);
            if (input != '\0') {
                printf("Dequeued: %c\n", input);
            }
            break;
        case 3:
            printQueue(&queue);
            break;
        case 4:
            printf("Current queue size: %d\n", getSize(&queue));
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    freeQueue(&queue);
    return 0;
}