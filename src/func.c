#include "chess_and_board.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isStandard; //是否符合規則，初始值1，符合
bool gameOverSign;  //遊戲是否結束，0結束
bool restart ;

char* array[9][9];
int xi,yi;//要移動的棋子
int xj,yj;//移動的目標位置
char save;//儲存
char load;//叫檔案



//生成棋盤
void chessboardBuilding()
{
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9 ; j ++) {
            array[i][j] = CROSS;
        }
        printf("\n");
    }
   
    //布置紅棋
    array[0][0] = array[0][8] = R(香);
    array[0][1] = array[0][7] = R(桂);
    array[0][2] = array[0][6] = R(銀);
    array[0][3] = array[0][5] = R(金);
    array[1][1] = R(飛);
	array[1][7] = R(角);
	for (int j=0; j<9; j++){
		array[2][j]= R(步);
	}
	array[0][4] = R(王);
    
    //布置藍棋
    array[8][0] = array[8][8] = B(香);
    array[8][1] = array[8][7] = B(桂);
    array[8][2] = array[8][6] = B(銀);
    array[8][3] = array[8][5] = B(金);
	array[7][7] = B(飛);
	array[7][1] = B(角);
	for (int j=0; j<9; j++){
		array[6][j]= B(步);
	}
	array[8][4] = B(王);
}

//打印棋盤
void printChessboard()
{
	system("clear");
	//fp = fopen("new_game_file_name.txt","w");
    printf("  \033[43;30m日本將棋歡迎您\033[0m\n\n");
	
    for (int i = 0; i < 9;  i ++) {
        for (int j = 0; j < 9; j ++) {
            printf("%s",array[i][j]);
        }
        printf("\n");
    }
}


//判斷是紅棋還是藍棋,紅旗返回1,藍棋返回-1,否則返回0
int redOrBlack(int x,int y)
{
    if (array[x][y] == R(香) || array[x][y] == R(桂) || array[x][y] == R(銀) || array[x][y] == R(金) || array[x][y] == R(王) || array[x][y] == R(飛) || array[x][y] == R(步)|| array[x][y] == R(角))
    {
        return  1;
    }
    else if (array[x][y] == B(香) || array[x][y] == B(桂) || array[x][y] == B(銀) || array[x][y] == B(金) || array[x][y] == B(王) || array[x][y] == B(飛) || array[x][y] == B(步)|| array[x][y] == B(角))
    {
        return -1;
    }
    else
        return 0;
}
//儲存棋局
void savedata()
{
	FILE *savedata;
	savedata = fopen("new_game_file_name.txt","w");
	for (int i = 0; i < 9;  i ++) {
		for (int j = 0; j < 9; j ++) {
			fprintf(savedata,"%s",array[i][j]);
		}
		fprintf(savedata,"\n");
	}
	//rename(old_game_file_name.txt, new_game_file_name.txt);
	fclose(savedata);
}

//改檔名

/*int rename(char *oldname, char *newname);
{
	if (rename(oldname, newname) == 0)
		printf("已經把檔案 %s 修改為 %s.\n", oldname, newname);
	else
		perror("rename");
	return 0;
}*/



//叫出棋局
/*int loadFile()
{		
	if(in == NULL){
		return 0;
	}
	//rename(new_game_file_name.txt, old_game_file_name.txt);
	else
	{
		return 1;
	}
}*/

//紅棋移動
void redMove()
{
	if (restart) {
        printf("違反遊戲規則，請重新輸入\n");
        restart = 0;
    }
	printf("\n\033[47;31m[玩家Y]是否儲存當前棋局(是請輸入S，否請輸入N):\033[0m \n");
	scanf("%s",&save);
	if(save=='s'||save=='S'){
		gameOverSign=0;
		exit(0);
	}
    printf("\n\033[47;31m[玩家Y]請輸入你要移動的棋子:\033[0m \n");
    scanf("%d %d",&xi,&yi);
    printf("\n\033[47;31m[玩家Y]請輸入你要放置的位置:\033[0m \n");
    scanf("%d %d",&xj,&yj);
    rulesOfAllKindsOfChessPieces();
    printChessboard();
}

//藍棋移動
void blackMove()
{
    if (restart) {
        printf("違反遊戲規則，請重新輸入\n");
        restart = 0;
    }
	printf("\n\033[47;34m[玩家X]是否儲存當前棋局(是請輸入S，否請輸入N):\033[0m \n");
	scanf("%s",&save);
	if(save=='s'||save=='S'){
		gameOverSign=0;
		exit(0);
	}
    printf("\n\033[47;34m[玩家X]請輸入你要移動的棋子:\033[0m \n");
    scanf("%d %d",&xi,&yi);
	if (xi == 115)
	{
		gameOverSign=0;
		exit(0);
	}	
    printf("\n\033[47;34m[玩家X]請輸入你要放置的位置:\033[0m \n");
    scanf("%d %d",&xj,&yj);

    rulesOfAllKindsOfChessPieces();
    printChessboard();
}


//判斷遊戲結束
void isGameOver()
{
    bool sign_r = 0;
    bool sign_b = 0;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            if (array[i][j] == R(王)) {
                sign_r = 1;
            }
            else if (array[i][j] == B(王))
            {
                sign_b = 1;
            }
        }
    }
    if ((sign_r == 0)||(sign_b == 0)) {
        gameOverSign = 0;
    }
}

//每種棋子的規則
void rulesOfAllKindsOfChessPieces()
{
//R（香）----------------------------------------
    if (array[xi][yi] == R(香))
    {
        if (yi == yj)//列坐標不變，同列移動
        {
            for (int i = xi+1; i < xj; i ++)
            {
                if (array[i][yj] != CROSS)
                    isStandard = 0;//如果初始位置和目標位置之間有棋子，則不符合規則
            }
        }
        if ((yi == yj)&& isStandard && (redOrBlack(xj, yj) != 1))//如果棋子直行、沒有犯規且落點不是紅棋，可以移動
		{
			array[xi][yi] = CROSS;
            array[xj][yj] = R(香);
        }
        else
        {
            restart = 1;
        }
    }

//B（香）----------------------------------------
    else if (array[xi][yi] == B(香))
    {
        
        if (yi == yj)//列坐標不變，同列移動
        {
            for (int i = xi-1; i > xj; i --)
            {
                if (array[i][yj] != CROSS)
                    isStandard = 0;
            }
        }
        if ((yi == yj)&& isStandard && redOrBlack(xj, yj) != -1)//如果棋子直行、沒有犯規且落點不是紅棋，可以移動
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = B(香);
        }
        else
        {
            restart = 1;
        }
    }

//R（桂）----------------------------------------
    else if (array[xi][yi] == R(桂))
    {
        if ((redOrBlack(xj, yj) != 1) && ((xj == xi+2 && yj == yi-1) || (xj == xi+2 && yj == yi+1)))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = R(桂);
        }
        else
        {
            restart = 1;
        }
    }
    
//B（桂）----------------------------------------
    else if (array[xi][yi] == B(桂))
    {
        if ((redOrBlack(xj, yj) != -1) && ((xj == xi-2 && yj == yi-1) || (xj == xi-2 && yj == yi+1)))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = B(桂);
        }
        else
        {
            restart = 1;
        }
    }
    
//R（飛）----------------------------------------
    else if (array[xi][yi] == R(飛))
    {
        if (yi == yj)//列坐標不變，同列移動
        {
            for (int i = xi+1; i < xj; i ++)
            {
                if (array[i][yi] != CROSS)
                    isStandard = 0;//如果初始位置和目標位置之間有棋子，則不符合規則
            }
            for (int i = xi-1; i > xj; i --)
            {
                if (array[i][yi] != CROSS)
                    isStandard = 0;
            }
        }
        else if (xi == xj)//行坐標不變，同行移動
        {
            for (int i = yi+1; i < yj; i ++)
                if (array[xi][i] != CROSS)
                    isStandard = 0;
            for (int i = yi-1; i > yj; i --)
                if (array[xi][i] != CROSS)
                    isStandard = 0;
        }
        
        if ((xi == xj || yi == yj)&& isStandard && (redOrBlack(xj, yj) != 1))//如果棋子直行、沒有犯規且落點不是紅棋，可以移動
        {
            
            array[xi][yi] = CROSS;
            array[xj][yj] = R(飛);
        }
        else
        {
            restart = 1;
        }
    }
    
//B（飛）----------------------------------------
    else if (array[xi][yi] == B(飛))
    {     
        if (yi == yj)//列坐標不變，同列移動
        {
            for (int i = xi+1; i < xj; i ++)
            {
                if (array[i][yi] != CROSS)
                    isStandard = 0;//如果初始位置和目標位置之間有棋子，則不符合規則
            }
            for (int i = xi-1; i > xj; i --)
            {
                if (array[i][yi] != CROSS)
                    isStandard = 0;
            }
        }
        else if (xi == xj)//行坐標不變，同行移動
        {
            for (int i = yi+1; i < yj; i ++)
                if (array[xi][i] != CROSS)
                    isStandard = 0;
            for (int i = yi-1; i > yj; i --)
                if (array[xi][i] != CROSS)
                    isStandard = 0;
        }
        if ((xi == xj || yi == yj)&& isStandard && redOrBlack(xj, yj) != -1)//如果棋子直行、沒有犯規且落點不是紅棋，可以移動
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = B(飛);
        }
        else
        {
            restart = 1;
        }
    }

//R（角）----------------------------------------
	else if (array[xi][yi] == R(角))
	{
        if (xi < xj && yi < yj )
        {
			for (int i = xi+1; i < xj; i ++)
            {
				for (int j = yi+1; j < yj; j++)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }            
        }
		else if (xi < xj && yi > yj )
        {
			for (int i = xi+1; i < xj; i ++)
            {
				for (int j = yi-1; j > yj; j --)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }
        }
		else if (xi > xj && yi > yj )
        {
			for (int i = xi-1; i > xj; i --)
            {
				for (int j = yi-1; j > yj; j --)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }
        }
		else if (xi > xj && yi < yj )
        {
			for (int i = xi-1; i > xj; i --)
            {
				for (int j = yi+1; j < yj; j ++)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }
        }
		if ((xj <= 8)&&(redOrBlack(xj, yj) != 1)&& isStandard && (abs(xj-xi)== abs(yj-yi)) && (xi != xj)&&(yi != yj))
		{
			array[xi][yi] = CROSS;
            array[xj][yj] = R(角);
		}
		else
		{
            restart = 1;
		}
    }

//B（角）-----------------------------------------
    else if (array[xi][yi] == B(角))
    {
        if (xi < xj && yi < yj )
        {
			for (int i = xi+1; i < xj; i ++)
            {
				for (int j = yi+1; j < yj; j++)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }            
        }
		else if (xi < xj && yi > yj )
        {
			for (int i = xi+1; i < xj; i ++)
            {
				for (int j = yi-1; j > yj; j --)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }
        }
		else if (xi > xj && yi > yj )
        {
			for (int i = xi-1; i > xj; i --)
            {
				for (int j = yi-1; j > yj; j --)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }
        }
		else if (xi > xj && yi < yj )
        {
			for (int i = xi-1; i > xj; i --)
            {
				for (int j = yi+1; j < yj; j ++)
				{
					if (array[i][j] != CROSS)
                    isStandard = 0;
				}
            }
        }
		if ((xj >= 2)&&(redOrBlack(xj, yj) != -1)&& isStandard && ((abs(xj-xi))== (abs(yj-yi)))&& (xi != xj)&&(yi != yj))
		{
			array[xi][yi] = CROSS;
            array[xj][yj] = B(角);
		}
		else
		{
            restart = 1;
		}
    }
//R（步）----------------------------------------
	else if (array[xi][yi] == R(步))
    {
        if (xi > xj)
            isStandard = 0;//如果倒退，則不符合規範
		
        if (xi <= 6){
            if ((xj != xi+1) || (yi != yj))
                isStandard = 0;//第3-7行時只能前進一步
		}
		if (isStandard && redOrBlack(xj, yj) != -1)//
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = R(步);
        }
        else
        {
            restart = 1;
        }
    }

//B（步）----------------------------------------
    else if (array[xi][yi] == B(步))
    {
        if (xi < xj)
            isStandard = 0;//如果倒退，則不符合規範
		
        if (xi >= 2){
            if ((xj != xi-1) || (yi != yj))
                isStandard = 0;//第3-7行時只能前進一步
		}

        if (isStandard && redOrBlack(xj, yj) != -1)//
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = B(步);
        }
        else
        {
            restart = 1;
        }
    }

//R（銀）----------------------------------------
    else if (array[xi][yi] == R(銀))
    {
        if ((redOrBlack(xj, yj) != 1) && ((xj == xi-1 && yj == yi-1 ) || (xj == xi-1 && yj == yi+1) || (xj == xi+1 && yj == yi-1 ) || (xj == xi+1 && yj == yi+1 )|| (xj == xi+1 && yj == yi)))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = R(銀);
        }
        else
        {
            restart = 1;
        }
    }
    
//B（銀）----------------------------------------
    else if (array[xi][yi] == B(銀))
    {
        if ((redOrBlack(xj, yj) != -1) && ((xj == xi-1 && yj == yi-1 ) || (xj == xi-1 && yj == yi+1 ) || (xj == xi+1 && yj == yi-1 ) || (xj == xi+1 && yj == yi+1 ) || (xj == xi-1 && yj == yi)))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = B(銀);
        }
        else
        {
            restart = 1;
        }
    }

//R（金）----------------------------------------
    else if (array[xi][yi] == R(金))
    {
        if ((xj >= 1)&&(redOrBlack(xj, yj) != 1) && ((xj == xi+1 && yj == yi-1 ) || (xj == xi+1 && yj == yi+1 )|| (xj == xi-1 && yj == yi) || (xj == xi+1 && yj == yi) ||(xj == xi && yj == yi+1)||(xj == xi && yj == yi-1)))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = R(金);
        }
        else
        {
            restart = 1;
        }
    }

//B（金）----------------------------------------
    else if (array[xi][yi] == B(金))
    {
        if ((xj <= 6)&&(redOrBlack(xj, yj) != 1) && ((xj == xi-1 && yj == yi-1 ) || (xj == xi-1 && yj == yi+1 ) || (xj == xi-1 && yj == yi) || (xj == xi+1 && yj == yi) ||(xj == xi && yj == yi+1)||(xj == xi && yj == yi-1)))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = B(金);
        }
        else
        {
            restart = 1;
        }
    }

//R（王）----------------------------------------
    else if (array[xi][yi] == R(王))
    {
        if ((redOrBlack(xj, yj) != 1)&&(((xj == xi)&&(yj == yi + 1 || yj == yi - 1))||((yj == yi)&&(xj == xi + 1 || xj == xi - 1)) || ((xj == xi-1) && (yj == yi-1 || yj == yi+1)) || ((xj == xi+1)&& (yj == yi-1 || yj == yi+1))))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = R(王);
        }
        else
        {
            restart = 1;
        }
    }

//B（王）----------------------------------------
    else if (array[xi][yi] == B(王))
	{
        if ((redOrBlack(xj, yj) != -1)&&(((xj == xi)&&(yj == yi + 1 || yj == yi - 1))||((yj == yi)&&(xj == xi + 1 || xj == xi - 1)) || ((xj == xi-1) && (yj == yi-1 || yj == yi+1)) || ((xj == xi+1)&& (yj == yi-1 || yj == yi+1))))
        {
            array[xi][yi] = CROSS;
            array[xj][yj] = B(王);
        }
        else
        {
            restart = 1;
        }
    }
	
    else {
        restart = 1;
    }
}
