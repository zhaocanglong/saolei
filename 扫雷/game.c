#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	memset(board, set, rows * cols*sizeof(board[0][0]));
}
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf(" ");
	for (i = 1; i <= row; i++)
	{
		printf(" %d", i);
	}
	printf("\n");
	for (i = 1; i <= row; ++i)
	{
		printf("%d", i);
		for (j = 1; j <= col; ++j)
		{
			printf(" %c",board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void SetMine(char board[ROWS][COLS], int row, int col,int *p)
{
	int i = 0;
	int j = 0;
	int count = 0;
	if ((*p) == 1)
	{
		count = easy__count;
	}
     if ((*p) == 2)
	{
		count = hard__count;
	}
    
	 while (count)
	{
		i = rand() % 9 + 1;
	    j = rand() % 9 + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	 }
	/* PrintBoard(board, row, col);*/
}
int CountMine(char board[ROWS][COLS], int x, int y);
void ClearBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int *p)
{
	int x = 0;
	int y = 0;
	int ret = 0;
	int count = 0;
	if (*p == 1)
	{
		count = easy__count;
	}
	if (*p == 2)
	{
		count = hard__count;
	}
	while (ret < row*col - count)
	{
		printf("请输入坐标");
	    scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				PrintBoard(mine, row, col);
				break;
			}
			if (mine[x][y] == '0')
			{
				count = CountMine(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, row, col);
				ret++;
			}

		}
		else
		{
			printf("坐标不合法\n");
		}
	}
	if (ret == row*col - easy__count)
	{
		printf("排雷成功\n");
		PrintBoard(mine, row, col);
	}
}
int CountMine(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0';
}