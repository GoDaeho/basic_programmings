#include <stdio.h>
#include <stdlib.h>     
#include <string.h>     

#define MAX 6                  // ������ ����
#define TRUE 1
#define FALSE 0

typedef struct Node* P_Node;    // ���������
typedef struct Node
{
	P_Node link;                // ����� ������ ��ũ
	int vtx;                    // ���� ��ȣ
}Node;

P_Node graph[MAX];              // ��������Ʈ ���� �ʱ� �����͹迭
short int mark[MAX];            // �˻��� �̿�� ��ŷ�迭
int matrix[MAX][MAX] = {        // �������
				 {0,1,1,0,0,1},
				 {1,0,0,1,1,0},
				 {1,0,0,0,0,1},
				 {0,1,1,0,0,0},
				 {0,1,0,0,0,1},
				 {0,0,1,0,0,0},
};

void init() // // ��������� ������� ���� ����Ʈ �����ϴ� �Լ�
{
	int x, y;

	P_Node move= nullptr;         // �̵�������
	P_Node st;					  // �� ������
	P_Node tmp= nullptr;          // �����Ҵ�

	for (x = 0; x < MAX; x++)
	{
		st = graph[x];         // �����̸鼭 ���� ����
		printf("���� %d�� ���� ����Ʈ", x+1);
		for (y = 0; y < MAX; y++)
		{
			if (matrix[x][y] != FALSE)  // matrix[x][y] == TRUE
			{

				tmp = (P_Node)malloc(sizeof(Node));
				tmp->vtx = y;     // vtx���� �� ��ȣ 

				if (graph[x] == st)   // �ʱ⿡ �ƹ����ᵵ ������
				{     // move�� tmp�ּҰ� �����ϰ� graph���� tmp�� �ּҰ� ������.
					move = tmp;
					graph[x] = tmp;
					printf("-> %d", (tmp->vtx)+1);
				}
				else       // ������ �����������
				{     // ��带 �����Ŵ
					move->link = tmp;
					move = tmp;
					printf("-> %d", (tmp->vtx)+1);

				}

			}
		}
		tmp->link = NULL;      // �������� NULL��
		puts("\n");
	}
}
void Clear_mark()     // ǥ�� û��
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



		   
