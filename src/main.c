#include "chess_and_board.h"
#include "stack.h"
#include <ev.h>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	int c;
	FILE *in;
	char * ptr;
    ptr = (char *) malloc(sizeof(char) * 60);
	//char buffer[100]={0};	
	in = fopen("new_game_file_name.txt", "r");

	if (in == NULL)
	{
		chessboardBuilding();
		printChessboard();  //打印棋盤
	}
	else
	{	
		while(!feof(in)) 
		{
			fgets(ptr, 60 ,in);
			printf("%s", ptr);
		}
		
	}
	//開始下棋
	int turn = -1;

	while (gameOverSign) {
		isStandard = 1;
		turn *= (-1);//雙方交替下棋
		switch (turn) {
			case 1:
				redMove();
				savedata();
				turn = (restart) ? (turn*-1) : turn;
				break;
			case -1:
				blackMove();
				savedata();
				turn = (restart) ? (turn*-1) : turn;
				break;
		}
		isGameOver();
	}
	printf("遊戲結束!\n");
	fclose(in);
	return 0;
}
