#include <stdio.h>

#define MAX_NQ 100005
#define MAX_XY 1505

int main() {
    int N, Q;
    int X[MAX_NQ], Y[MAX_NQ];
    int field[MAX_XY][MAX_XY];
    int a[MAX_NQ], b[MAX_NQ], c[MAX_NQ], d[MAX_NQ];

    // 入力
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &X[i], &Y[i]);
    }
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }

    // 初期化
    for (int x = 1; x <= 1500; x++) {
        for (int y = 1; y <= 1500; y++) {
            field[x][y] = 0;
        }
    }
    // 代入
    for (int i = 1; i <= N; i++) {
        field[X[i]][Y[i]]++;
    }

    // 累積和計算
    for (int x = 1; x <= 1500; x++) {
        // y軸方向
        for (int y = 1; y <= 1500; y++) {
            field[x][y] = field[x][y - 1] + field[x][y];
        }
        // x軸方向
        for (int y = 1; y <= 1500; y++) {
            field[x][y] = field[x - 1][y] + field[x][y];
        }
    }

    // 出力
    for (int que = 1; que <= Q; que++) {
        printf("%d\n", field[a[que] - 1][b[que] - 1] + field[c[que]][d[que]]
                         - field[a[que] - 1][d[que]] - field[c[que]][b[que] - 1]);
    }
}