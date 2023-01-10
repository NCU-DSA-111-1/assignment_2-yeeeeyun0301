#include "stack.h"
Node_t *init_node(){
    Node_t* stk = (Node_t*)malloc(sizeof(Node_t)); 
    stk = NULL;
    return stk;
}

Stack_t *init_stack(){
    Stack_t* stk = (Stack_t*)malloc(sizeof(Stack_t)); 
    stk->top = NULL;
    return stk;
}

void push(Stack_t *const stk, void* src){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->value = src;
    node->previous = NULL;

    if(stk->top) {
        stk->top->next = node;
        node->previous = stk->top;
    }
    stk->top = node;

    return;
}

int is_empty(Stack_t *const stk){
    return !stk->top;
}

void pop(Stack_t *const stk, void *des, long size){
    if(is_empty(stk)){
        printf("Stack is empty!\n");
        return;
    }

    Node_t *temp =  stk->top;
    stk->top = temp->previous;
    memcpy(des, temp->value, size);
    free(temp);
    return;
}