#include <stdio.h>
#define MAX 100

int M[5][5] = {
    {0,    MAX, 1,    MAX, 10},
    {MAX,  0,   MAX,  1,   5},
    {MAX,  1,   0,    MAX, 7},
    {MAX,  MAX, MAX,  0,   1},
    {MAX,  MAX, MAX,  MAX, 0}
};

int Path[5][5];

void Floyd(int M[][5], int Path[][5], int vexnum) {
    for (int k = 0; k < vexnum; k++) {
        for (int i = 0; i < vexnum; i++) {
            for (int j = 0; j < vexnum; j++) {
                if (M[i][j] > M[i][k] + M[k][j]) {
                    M[i][j] = M[i][k] + M[k][j];
                    Path[i][j] = k;
                }
            }
        }
    }
}

void FloydFind(int i, int j) {
    if (Path[i][j] != -1) {
        FloydFind(i, Path[i][j]);
        FloydFind(Path[i][j], j);
    } else {
        printf("->%d", j);
    }
}

void find(int i, int j) {
    printf("%d", i);
    FloydFind(i, j);
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            Path[i][j] = -1;
        }
    }
    int vexnum = 5;
    Floyd(M, Path, vexnum);
    printf("Hello, Floyd!\n");
    find(0, 4);
    return 0;
}