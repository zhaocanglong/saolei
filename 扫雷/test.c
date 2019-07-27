#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu1()
{
	printf("*********************************************\n");
	printf("************1.play   0.exit******************\n");
	printf("*********************************************\n");
}
void menu2()
{
	printf("*********************************************\n");
	printf("************1.easy  2.hard******************\n");
	printf("*********************************************\n");
}
void game(int *p)
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	srand((unsigned int)time(NULL));
	InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
	PrintBoard(show, ROW, COL);
	SetMine(mine, ROW, COL,p);
	
	ClearBoard(mine, show, ROW, COL,p);
}
void test()
{
	int input = 0;
	int select = 0;
	do
	{
		menu1();
		printf("请输入选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			menu2();
			printf("请输入选项:>");
			scanf("%d", &select);
			switch (select)
			{
			    case 1:
					game(&select);
					break;
			    case 2:
				    game(&select);
				    break;
				default:
					break;
			}
		}
		case 0:
			break;
		default:
			break;
		}

	} while (input);

	
}
int main()
{
  test();
  return 0;
}
