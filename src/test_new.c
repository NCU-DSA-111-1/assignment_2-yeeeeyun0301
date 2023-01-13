#include "stack.h"
#include "chess_and_board.h"
#include <ev.h>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isStandard = 1; //是否符合規則，初始值1，符合
bool gameOverSign = 1; //遊戲是否結束，0結束
bool restart = 0;

int main()
{
    
    int i, j;

    Stack_t *task1;
    task1=init_stack();
    for(i=0; i<ROW ;i++){
        for (int j = 0; j < COL ; j ++){
            push(task1,(void*) &CROSS);
        }
    }
    //printf(task1);

    //init_stack()
    return 0;

}