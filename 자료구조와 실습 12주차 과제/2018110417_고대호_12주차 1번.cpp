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
	// 그래프 정보 
	int graph[][SIZE] = {
		{0,0,25,15,0,0},
		{15,0,0,0,10,0},
		{10,50,0,0,65,0},
		{0,20,0,0,35,0},
		{0,0,0,30,0,0},
		{0,0,0,3,0,0} 
	};

	// 도시 정보
	c city[SIZE];

	// 0->다른 도시 간 거리 정보 
	int distance[SIZE] = { 0 };

	// 최단거리 찾기 
	dijkstra_find(city, graph, distance);

	printf("\n");
	//출력 
	for (int i = 0; i < SIZE; i++)
		printf("   v0에서 v%d까지 최단 거리: %d\n",
			i, city[i].distance);
	printf("\n   ");
}


// 다익스트라 알고리즘 길찾기 
// parameter : 도시정보 city, 거리정보 h, 최단거리 저장 dist
void dijkstra_find(c* city, int graph[][SIZE], int* distance)
{
	int footstep[SIZE] = { 1, 0 };  // 방문완료한 도시 (0번 도시는 방문처리)
	for (int i = 0; i < SIZE; i++)  // 첫 배열 복사 (0에서 연결된 도시 정보)
	{
		distance[i] = graph[0][i];
		city[i].upcity = 0;
		city[i].distance = distance[i];
	}


	//도시를 다 방문할 때까지 반복문 수행 
	int i;
	while ((i = min_find(footstep, distance)) != -1)
	{
		footstep[i] = 1;  // 방문처리
		for (int j = 1; j < SIZE; j++)
		{
			// 새로운 길이 현재 저장된 값보다 더 작거나 0인 경우 갱신 
			if (graph[i][j] != 0 && (distance[i] + graph[i][j] < distance[j] || distance[j] == 0))
			{
				distance[j] = distance[i] + graph[i][j];
				city[j].upcity = i;
				city[j].distance = distance[j];
			}
		}
	}
}

// 방문하지 않은 도시 중 가장 적은 값의 노드를 찾음 
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
	if (j == -1)  // 모두 방문했을 경우
		return -1;
	else  // 방문할 도시가 남은 경우
		return j;
}