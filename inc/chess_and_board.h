#ifndef CHESS_AND_BOARD_H
#define CHESS_AND_BOARD_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//定義
#define ROW  9
#define COL  9
#define R(piece) "\033[47;31m"#piece"\033[0m"//紅色棋子，底色為白
#define B(piece) "\033[47;34m"#piece"\033[0m"//藍色棋子，底色為白
#define CROSS "\033[47;33m口\033[0m" //間隔，底色為白
//#define PRINT_BACK_WHI  printf("\033[47m"); //設置背景色為白色



//------------chess board---------------//
void chessboardBuilding(); //生成棋盤
void printChessboard(); //打印棋盤

//----------------chess----------------//



//--------------rule-------------------//
void rulesOfAllKindsOfChessPieces(); //每種棋子的走法規則


//------------chess move----------------//
void redMove(); //紅棋移動
void blackMove(); //藍棋移動
int redOrBlack(int x,int y); //判斷是紅棋還是藍棋,紅旗返回1,黑棋返回-1,否則返回0




void isGameOver(); //判斷遊戲結束

//------------read & write---------------//
void savedata();

//------------display time---------------//



#endif