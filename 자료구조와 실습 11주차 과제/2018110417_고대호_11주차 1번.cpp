#include <stdio.h>
#include <stdlib.h>     
#include <string.h>     

#define MAX 6                  // 정점의 갯수
#define TRUE 1
#define FALSE 0

typedef struct Node* P_Node;    // 노드포인터
typedef struct Node
{
	P_Node link;                // 노드의 포인터 링크
	int vtx;                    // 정점 번호
}Node;

P_Node graph[MAX];              // 인접리스트 구성 초기 포인터배열
short int mark[MAX];            // 검색시 이용될 마킹배열
int matrix[MAX][MAX] = {        // 인접행렬
				 {0,1,1,0,0,1},
				 {1,0,0,1,1,0},
				 {1,0,0,0,0,1},
				 {0,1,1,0,0,0},
				 {0,1,0,0,0,1},
				 {0,0,1,0,0,0},
};

void init() // // 인접행렬을 기반으로 인접 리스트 구성하는 함수
{
	int x, y;

	P_Node move= nullptr;         // 이동포인터
	P_Node st;					  // 비교 포인터
	P_Node tmp= nullptr;          // 동적할당

	for (x = 0; x < MAX; x++)
	{
		st = graph[x];         // 움직이면서 비교할 변수
		printf("정점 %d의 인접 리스트", x+1);
		for (y = 0; y < MAX; y++)
		{
			if (matrix[x][y] != FALSE)  // matrix[x][y] == TRUE
			{

				tmp = (P_Node)malloc(sizeof(Node));
				tmp->vtx = y;     // vtx값에 점 번호 

				if (graph[x] == st)   // 초기에 아무연결도 없을때
				{     // move가 tmp주소값 갖게하고 graph역시 tmp의 주소값 가진다.
					move = tmp;
					graph[x] = tmp;
					printf("-> %d", (tmp->vtx)+1);
				}
				else       // 뭔가가 연결되있을때
				{     // 노드를 연결시킴
					move->link = tmp;
					move = tmp;
					printf("-> %d", (tmp->vtx)+1);

				}

			}
		}
		tmp->link = NULL;      // 마지막에 NULL값
		puts("\n");
	}
}
void Clear_mark()     // 표시 청소
{
	      int i;
          for (i = 0; i < MAX; i++)
	      {
              mark[i] = FALSE;
	      }
}
			
int main()
{
	int v;                     
	Clear_mark();         
	init();         

	return 0;
}



		   
