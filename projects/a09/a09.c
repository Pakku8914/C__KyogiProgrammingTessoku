#include <stdio.h>

#define MAX_HW 1505
#define MAX_N  100005

int main() {
    int H, W, N;
    int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
    int field[MAX_HW][MAX_HW];

    // 入力
    scanf("%d%d%d", &H, &W, &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
    }
    // 初期化
    for (int h = 0; h <= H; h++) {
        for (int w = 0; w <= W; w++) {
            field[h][w] = 0;
        }
    }

    // 代入
    for (int i = 1; i <= N; i++) {
        field[A[i]][B[i]]++;
        field[A[i]][D[i] + 1]--;
        field[C[i] + 1][B[i]]--;
        field[C[i] + 1][D[i] + 1]++;
    }

    // 累積和計算
    for (int h = 1; h <= H; h++) {
        // w方向
        for (int w = 1; w <= W; w++) {
            field[h][w] = field[h][w] + field[h][w - 1];
        }
        // h方向
        for (int w = 1; w <= W; w++) {
            field[h][w] = field[h][w] + field[h - 1][w];
        }
    }

    // 出力
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            printf("%d ", field[h][w]);
        }
        printf("\n");
    }
}