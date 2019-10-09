#include<stdio.h>
#include<stdlib.h>
#define m 5
#define n 5
#define startx 1
#define starty 1
#define endx 5
#define endy 5

typedef struct
{
	int x, y;
	int pre;
}coordinate;

int maze[m + 2][n + 2] = {
	{ 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1 },
};

coordinate move[8] = { { -1, 0, 0 }, { -1, 1, 0 }, { 0, 1, 0 }, { 1, 1, 0 }, { 1, 0, 0 }, { 1, -1, 0 }, { 0, -1, 0 }, { -1, -1, 0 } };

int main(void)
{
	coordinate sq[m*n];
	coordinate nowlocat;		//��ǰλ�õ�����
	coordinate explore;			//̽��������
	int front = 0, rear = 0;
	int path = 0;
	int flag = 0;
	int pre;
	int i, j;

	maze[startx][starty] = 1;
	nowlocat.x = startx, nowlocat.y = starty, nowlocat.pre = -1;
	sq[rear] = nowlocat;
	rear++;

	//Ѱ�����·��
	while (front != rear)
	{
		nowlocat = sq[front];
		for (path = 0; path < 8; path++)
		{
			explore.x = nowlocat.x + move[path].x, explore.y = nowlocat.y + move[path].y;

			//Ѱ�ҿ��ƶ�·��
			if (maze[explore.x][explore.y] == 0)
			{
				maze[explore.x][explore.y] = -1;
				explore.pre = front;
				sq[rear] = explore;
				rear++;
			}

			//�ж��Ƿ�Ϊ�յ�
			if (explore.x == endx&&explore.y == endy)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
		front++;
	}

	//��ӡ���·��
	if (flag==1)
	{
		rear--;
		pre = sq[rear].pre;

		while (rear != -1)
		{
			maze[sq[rear].x][sq[rear].y] = 0;
			rear--;
		}

		maze[endx][endy] = 2;

		while (pre != -1)
		{
			maze[sq[pre].x][sq[pre].y] = 2;
			pre = sq[pre].pre;
		}

		for (i = 0; i < m + 2; i++)
		{
			for (j = 0; j < n + 2; j++)
			{
				printf(" %d,", maze[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("�޿���·��");
	}

	system("pause");
	return 0;
}