#include <stdio.h>
#define SIZE 6

typedef struct {
	int upcity;
	int distance;
}c;

void dijkstra_find(c* city, int graph[][SIZE], int* distance);
int min_find(int* footstep, int* distance);

void main()
{
	// �׷��� ���� 
	int graph[][SIZE] = {
		{0,0,25,15,0,0},
		{15,0,0,0,10,0},
		{10,50,0,0,65,0},
		{0,20,0,0,35,0},
		{0,0,0,30,0,0},
		{0,0,0,3,0,0} 
	};

	// ���� ����
	c city[SIZE];

	// 0->�ٸ� ���� �� �Ÿ� ���� 
	int distance[SIZE] = { 0 };

	// �ִܰŸ� ã�� 
	dijkstra_find(city, graph, distance);

	printf("\n");
	//��� 
	for (int i = 0; i < SIZE; i++)
		printf("   v0���� v%d���� �ִ� �Ÿ�: %d\n",
			i, city[i].distance);
	printf("\n   ");
}


// ���ͽ�Ʈ�� �˰��� ��ã�� 
// parameter : �������� city, �Ÿ����� h, �ִܰŸ� ���� dist
void dijkstra_find(c* city, int graph[][SIZE], int* distance)
{
	int footstep[SIZE] = { 1, 0 };  // �湮�Ϸ��� ���� (0�� ���ô� �湮ó��)
	for (int i = 0; i < SIZE; i++)  // ù �迭 ���� (0���� ����� ���� ����)
	{
		distance[i] = graph[0][i];
		city[i].upcity = 0;
		city[i].distance = distance[i];
	}


	//���ø� �� �湮�� ������ �ݺ��� ���� 
	int i;
	while ((i = min_find(footstep, distance)) != -1)
	{
		footstep[i] = 1;  // �湮ó��
		for (int j = 1; j < SIZE; j++)
		{
			// ���ο� ���� ���� ����� ������ �� �۰ų� 0�� ��� ���� 
			if (graph[i][j] != 0 && (distance[i] + graph[i][j] < distance[j] || distance[j] == 0))
			{
				distance[j] = distance[i] + graph[i][j];
				city[j].upcity = i;
				city[j].distance = distance[j];
			}
		}
	}
}

// �湮���� ���� ���� �� ���� ���� ���� ��带 ã�� 
int min_find(int* footstep, int* distance)
{
	int min = 10000;
	int j = -1;
	for (int i = 1; i < SIZE; i++)
		if (distance[i] != 0 && distance[i] < min && footstep[i] == 0)
		{
			min = distance[i];
			j = i;
		}
	if (j == -1)  // ��� �湮���� ���
		return -1;
	else  // �湮�� ���ð� ���� ���
		return j;
}