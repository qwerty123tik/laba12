#include"Header.h"

void initQueue(CharQueue* queue, int Maxsize) {
    queue->data = (char*)malloc(Maxsize * sizeof(char));
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

    /*if (queue->size > 1 && c == queue->data[(queue->rear - 1 + queue->Maxsize) % queue->Maxsize]) {
        printf("Last two elements are the same ('%c'). Current queue size: %d\n", c, queue->size);
    }*/
    int prevIndex = (queue->rear - 1 + queue->Maxsize) % queue->Maxsize;
    if (queue->size > 1 && c == queue->data[prevIndex]) {
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