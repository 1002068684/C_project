#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			 board[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = COUNT;
	while (count) {
		int x = rand() % row + 1;  //1-9
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS],int x,int  y) {
	int a = 0;
	int b = 0;
	int count = 0;
	for (a = x - 1; a <= x + 1; a++) {
		for (b = y - 1; b <= y + 1; b++) {
			if (a != x && b != y) {
				//判断是否有雷
				if (mine[a][b] == '1') {
					count++;
				}
			}
		}
	}
	return count;
}

//扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	//9*9-10=71
	while (win<row*col- COUNT) {
		printf("请输入排查雷的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//坐标合法
			if (mine[x][y] == '1') {
				//炸死
				printf("炸死");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				//不是雷
				//计算x，y坐标周围几个雷
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
			}
		}
		else {
			printf("输入坐标非法，请重新输入!\n");
		}
	}
	if (win == row * col - COUNT) {
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}

}