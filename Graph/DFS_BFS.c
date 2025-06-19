#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef char VertexType;
typedef int EdgeType;
// 邻接矩阵法
typedef struct MGrah {
    VertexType vex[MAXSIZE];
    EdgeType edge[MAXSIZE][MAXSIZE];
    int vexNum, edgeNum;
}MGraph;

typedef struct queue {
    int front, rear;
    int Q[MAXSIZE];
}*queue;

void creatGraph(MGraph *G) {
    G->vexNum = 9;
    G->edgeNum = 15;
    for (int i=0; i<G->vexNum; i++) {
        G->vex[i] = 'A'+i;
    }
    for (int i=0; i<G->vexNum; i++) {
        for (int j=0; j<G->vexNum; j++) {
            G->edge[i][j] = 0;
        }
    }
    	//A-B A-F
	G->edge[0][1] = 1;
	G->edge[0][5] = 1;

	//B-C B-G B-I
	G->edge[1][2] = 1;
	G->edge[1][6] = 1;
	G->edge[1][8] = 1;

	//C-D C-I
	G->edge[2][3] = 1;
	G->edge[2][8] = 1;

	//D-E D-G D-H D-I
	G->edge[3][4] = 1;
	G->edge[3][6] = 1;
	G->edge[3][7] = 1;
	G->edge[3][8] = 1;

	//E-F E-H
	G->edge[4][5] = 1;
	G->edge[4][7] = 1;

	//F-G
	G->edge[5][6] = 1;

	//G-H
	G->edge[6][7] = 1;
    for (int i=0; i<G->vexNum; i++) {
        for (int j=i; j<G->vexNum; j++) {
            if (G->edge[i][j] == 1) {
                G->edge[j][i] = G->edge[i][j];
            }
        }
    }
}

void dfs(MGraph G, int i, int *visited) {
    visited[i] = 1;
    printf("%c ", G.vex[i]);
    for (int j=0; j<G.vexNum; j++) {
        if (G.edge[i][j]==1 && visited[j]==0) {
            dfs(G, j, visited);
        }
    }
}

void bfs(MGraph G, int *visited) {
    queue q = (queue)malloc(sizeof(queue));
    q->front = 0;
    q->rear = 0;
    int i = 0;
    visited[i] = 1;
    printf("%c ", G.vex[i]);
    q->Q[q->rear] = i;
    q->rear++;
    while (q->rear != q->front) {
        i = q->front;
        q->front++;
        for (int j=0; j<G.vexNum; j++) {
            if (G.edge[i][j]==1 && visited[j]==0) {
                printf("%c ", G.vex[j]);
                visited[j] = 1;
                q->Q[q->rear] = j;
                q->rear++;
            }
        }
    }
    free(q);
}

int main() {
    MGraph G;
    creatGraph(&G);
    int visited[MAXSIZE] = {0}; //记录被访问过的节点
    dfs(G, 0, visited);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    bfs(G, visited);
    return 0;
}