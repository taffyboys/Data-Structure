#include <stdio.h>
#define MAXSIZE 100
#define MAX 0x7fffffff

typedef char VertexType;
typedef int EdgeType;
// 邻接矩阵法
typedef struct MGrah {
    VertexType vex[MAXSIZE];
    EdgeType edge[MAXSIZE][MAXSIZE];
    int vexNum, edgeNum;
}MGraph;

void creatGraph(MGraph *G) {
    G->vexNum = 9;
    G->edgeNum = 15;
    for (int i=0; i<G->vexNum; i++) {
        G->vex[i] = 'A'+i;
    }
    for (int i=0; i<G->vexNum; i++) {
        for (int j=0; j<G->vexNum; j++) {
            G->edge[i][j] = MAX;
        }
    }
    //A-B A-F
	G->edge[0][1] = 10;
	G->edge[0][5] = 11;

	//B-C B-G B-I
	G->edge[1][2] = 18;
	G->edge[1][6] = 16;
	G->edge[1][8] = 12;

	//C-D C-I
	G->edge[2][3] = 22;
	G->edge[2][8] = 8;

	//D-E D-G D-H D-I
	G->edge[3][4] = 20;
	G->edge[3][6] = 24;
	G->edge[3][7] = 16;
	G->edge[3][8] = 21;

	//E-F E-H
	G->edge[4][5] = 26;
	G->edge[4][7] = 7;

	//F-G
	G->edge[5][6] = 17;

	//G-H
	G->edge[6][7] = 19;
    for (int i=0; i<G->vexNum; i++) {
        for (int j=i; j<G->vexNum; j++) {
            if (G->edge[i][j]!=MAX) {
                G->edge[j][i] = G->edge[i][j];
            }
        }
    }
}

void prim(MGraph *G) {
    int i, j, k;
    int min;
    //表示当前点(connection某点)对应其他点的路径权值
    //若权值为0表示该对应的点和当前点已经建立连接，不能再选中
    int weight[MAXSIZE];
    //值和下标表示两个点的连接
    //最终得到的connection即表示prim生成树
    int connection[MAXSIZE];

    //从A开始
    weight[0] = 0;
    connection[0] = 0;
    //A点和自己连过了，从下一个点开始当前初始化
    for (i=1; i<G->vexNum; i++) {
        //edge的行索引表示当前点
        weight[i] = G->edge[0][i];
        connection[i] = 0; //初始化,相当于A连了其他所有点
    }

    for (i=1; i<G->vexNum; i++) {
        min = MAX;
        j = 0;
        k = 0;
        //连接最小值
        while (j<G->vexNum) {
            if (weight[j]!=0&&weight[j]<min) {
                min = weight[j]; //更新最小值
                k = j;
            }
            j++;
        }
        printf("(%c, %c)\n", G->vex[connection[k]], G->vex[k]);
        //由于connection中A与所有节点连接，所以这里不必再给conn赋值，只用更新相应的weight为0
        weight[k] = 0; //标记已访问
        //寻找新连接的节点的新边
        for (j = 0; j<G->vexNum; j++) {
            if (weight[j]!=0&&G->edge[k][j]<weight[j]) {
                weight[j] = G->edge[k][j];
                connection[j] = k; //有更小的权值就连接
            }
        }
    }
    return;
}

int main() {
    MGraph G;
    creatGraph(&G);
    prim(&G);
    return 0;
}