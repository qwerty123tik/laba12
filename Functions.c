#include"Header.h"

void initQueue(CharQueue* queue, int Maxsize) {
    queue->data = (char*)malloc(Maxsize * sizeof(char));
    if (queue->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->frnt = 0;
    queue->rear = -1;
    queue->Maxsize = Maxsize;
    queue->size = 0;
}

bool isempty(CharQueue* queue) {
    return queue->size == 0;
}

bool isfull(CharQueue* queue) {
    return queue->size == queue->Maxsize;
}

void insert(CharQueue* queue, char c) {
    if (isfull(queue)) {
        printf("Queue if full. Cannot add %c\n", c);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->Maxsize;
    queue->data[queue->rear] = c;
    queue->size++;
    printf("Added '%c' to queue\n", c);

    if (queue->size > 1 && c == queue->data[(queue->rear - 1 + queue->Maxsize) % queue->Maxsize]) {
        printf("Last two elements are the same ('%c'). Current queue size: %d\n", c, queue->size);
    }
}

char removeQueue(CharQueue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return '\0';
    }
    char c = queue->data[queue->frnt];
    queue->frnt = (queue->frnt + 1) % queue->Maxsize;
    queue->size--;
    return c;
}

int getSize(CharQueue* queue) {
    return queue->size;
}

void printQueue(CharQueue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents (front to rear): ");
    int count = 0;
    int index = queue->frnt;

    while (count < queue->size) {
        printf("%c ", queue->data[index]);
        index = (index + 1) % queue->Maxsize;
        count++;
    }
    printf("\n");
}

void freeQueue(CharQueue* queue) {
    free(queue->data);
    queue->data = NULL;
    queue->frnt = queue->rear = -1;
    queue->Maxsize = queue->size = 0;
}


//dek
void insertFrnt(CharQueue* queue, char c) {
    if (isfull(queue)) {
        printf("Queue if full. Cannot add %c\n", c);
        return;
    }
    if (queue->frnt == -1) {
        queue->frnt = 0;
        queue->rear = 0;
    }
    else if (queue->frnt == 0) {
        queue->frnt = queue->Maxsize - 1;
    }
    else {
        queue->frnt--;
    }

    queue->data[queue->frnt] = c;
    queue->size++;
    printf("Added '%c' to front\n", c);

    if (queue->size > 1 && c == queue->data[queue->rear]) {
        printf("Front and rear elements are the same ('%c'). Current deque size: %d\n", c, queue->size);
    }
}

void insertRear(CharQueue* queue, char c) {
    if (isfull(queue)) {
        printf("Queue if full. Cannot add %c\n", c);
        return;
    }
    if (queue->frnt == -1) {
        queue->frnt = 0;
        queue->rear = 0;
    }
    else if (queue->rear == queue->Maxsize - 1) {
        queue->rear = 0;
    }
    else {
        queue->rear++;
    }

    queue->data[queue->rear] = c;
    queue->size++;
    printf("Added '%c' to rear\n", c);

    if (queue->size > 1 && c == queue->data[queue->frnt]) {
        printf("Front and rear elements are the same ('%c'). Current deque size: %d\n", c, queue->size);
    }
}

char deleteFrnt(CharQueue* queue) {
    if (isempty(queue)) {
        printf("Deque is empty\n");
        return '\0';
    }

    char c = queue->data[queue->frnt];

    if (queue->frnt == queue->rear) {
        queue->frnt = -1;
        queue->rear = -1;
    }
    else {
        queue->frnt = (queue->frnt + 1) % queue->Maxsize;
    }
    queue->size--;
    return c;
}

char deleteRear(CharQueue* queue) {
    if (isempty(queue)) {
        printf("Deque is empty\n");
        return '\0';
    }

    char c = queue->data[queue->rear];

    if (queue->frnt == queue->rear) {
        queue->frnt = -1;
        queue->rear = -1;
    }
    else if (queue->rear == 0) {
        queue->rear = queue->Maxsize - 1;
    }
    else {
        queue->rear--;
    }
    queue->size--;
    return c;
}

//taski
void WorkWithQueue(CharQueue* queue) {
    int choice;
    char input;

    do {
        printf("\nQueue menu:\n");
        printf("1. Insert (add character)\n");
        printf("2. Remove (remove frim front)\n");
        printf("3. Print queue\n");
        printf("4. Get queue size\n");
        printf("5.  Back to main menu\n");
        printf("Enter choice: ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("Enter character to enqueue: ");
            scanf_s("%c", &input, 1);
            insert(queue, input);
            break;
        case 2:
            input = removeQueue(&queue);
            if (input != '\0') {
                printf("Dequeued: %c\n", input);
            }
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            printf("Current queue size: %d\n", getSize(queue));
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        }
    } while (true);
}

void WorkWithDek(CharQueue* queue) {
    int choice;
    char input;
    bool addToFront = true;

    do {
        printf("\nDek menu:\n");
        printf("1. Insert next element (alternating sides)\n");
        printf("2. Insert to front\n");
        printf("3. Insert to rear\n");
        printf("4. Delete from front\n");
        printf("5. Delete from rear\n");
        printf("6. Get current size\n");
        printf("7. Print dek\n");
        printf("8.  Back to main menu\n");
        printf("Enter choice: ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("Enter character: ");
            scanf_s(" %c", &input, 1);
            if (addToFront) {
                insertFrnt(queue, input);
            }
            else {
                insertRear(queue, input);
            }
            addToFront = !addToFront;
            break;
        case 2:
            printf("Enter character: ");
            scanf_s(" %c", &input,1);
            insertFrnt(queue, input);
            break;
        case 3:
            printf("Enter character: ");
            scanf_s(" %c", &input,1);
            insertRear(queue, input);
            break;
        case 4:
            input = deleteFrnt(queue);
            if (input != '\0') {
                printf("Deleted from front: %c\n", input);
            }
            break;
        case 5:
            input = deleteRear(queue);
            if (input != '\0') {
                printf("Deleted from rear: %c\n", input);
            }
            break;
        case 6:
            printf("Current queue size: %d\n", getSize(queue));
            break;
        case 7:
            printQueue(queue);
            break;
        case 8:
            return;
        default:
            printf("Invalid choice\n");
        }
    } while (true);
    freeQueue(&queue);
}
