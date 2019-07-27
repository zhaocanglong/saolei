#ifndef  ____game__h___
#define  ____game__h___


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define easy__count 40
#define hard__count 20
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col,int* p);
void ClearBoard(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int* p);
int CountMine(char board[ROWS][COLS], int x, int y);
#endif    //_____game_h___