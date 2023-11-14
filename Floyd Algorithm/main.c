#include <stdio.h>
#define MAX_VERTICES 100
#define INF 10000

typedef struct graphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];
int P[MAX_VERTICES][MAX_VERTICES];

// floyd 알고리즘
void floyd(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			A[i][j] = g->weight[i][j];
		}
	}

	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			P[i][j] = -1;
		}
	}

	for (int k = 0; k < g->n; k++) {
		for (int i = 0; i < g->n; i++) {
			for (int j = 0; j < g->n; j++) {
				if (A[i][k] + A[k][j] < A[i][j]) {
					A[i][j] = A[i][k] + A[k][j];
					P[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	int start = 0;
	int end = 0;

	GraphType g = { 10,
	{{0,3,INF,INF,INF,11,12,INF,INF,INF},
	{3,0,5,4,1,7,8,INF,INF,INF},
	{INF,5,0,2,INF,INF,6,5,INF,INF},
	{INF,4,2,0,13,INF,INF,14,INF,16},
	{INF,1,INF,13,0,9,INF,INF,18,17},
	{11,7,INF,INF,9,0,INF,INF,INF,INF},
	{12,8,6,INF,INF,INF,0,13,INF,INF},
	{INF,INF,5,14,INF,INF,13,0,INF,15},
	{INF,INF,INF,INF,18,INF,INF,INF,0,10},
	{INF,INF,INF,16,17,INF,INF,15,10,0}}
	};

	floyd(&g);

	printf("Floyd-Algorithm\n");

	for (int i = 0; i < 10; i++) {
		printf("start Node : ");
		scanf_s("%d", &start);
		printf("end Node : ");
		scanf_s("%d", &end);

		printf("shortest Disttance : %d\n\n", A[start - 1][end - 1]);

		printf("경로 : %d -> ",start);

		int i = start - 1;
		int j = end - 1;

		while (1) {
			if (P[i][j] + 1 == 0) break;

			printf("%d -> ", P[i][j] + 1);
			j = P[i][j] + 1;
		}

		printf("%d\n\n", end);
	}

	return 0;
}

