#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Node{
    void *value;
    struct Node *previous;
    struct Node *next;
}Node_t;

typedef struct Stack{
    Node_t *top;
    //
}Stack_t;

void push(Stack_t *const , void* );
int is_empty(Stack_t *const stk);
void pop(Stack_t *const stk, void *des, long size);

#endif