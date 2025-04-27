#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct {
    char* data;
    int frnt;
    int rear;
    int Maxsize;
    int size;
} CharQueue;

void initQueue(CharQueue* queue, int Maxsize);
bool isempty(CharQueue* queue);
bool isfull(CharQueue* queue);
void insert(CharQueue* queue, char c);
char removeQueue(CharQueue* queue);
int getSize(CharQueue* queue);
void printQueue(CharQueue* queue);
void freeQueue(CharQueue* queue);

void insertFrnt(CharQueue* queue, char c);
void insertRear(CharQueue* queue, char c);
char deleteFrnt(CharQueue* queue);
char deleteRear(CharQueue* queue);

void WorkWithQueue();
void WorkWithDek();