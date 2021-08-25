#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			 board[i][j] = set;
		}
	}
}

//��ӡ����
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

//������
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
				//�ж��Ƿ�����
				if (mine[a][b] == '1') {
					count++;
				}
			}
		}
	}
	return count;
}

//ɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	//9*9-10=71
	while (win<row*col- COUNT) {
		printf("�������Ų��׵����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//����Ϸ�
			if (mine[x][y] == '1') {
				//ը��
				printf("ը��");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				//������
				//����x��y������Χ������
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
			}
		}
		else {
			printf("��������Ƿ�������������!\n");
		}
	}
	if (win == row * col - COUNT) {
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, row, col);
	}

}