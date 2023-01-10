#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stdbool.h>

typedef struct Node{
    void *value;
    struct Node *previous;
    struct Node *next;
}Node_t;

typedef struct Stack{
    Node_t *top;
    //
}Stack_t;