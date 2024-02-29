#include <stdio.h>

#define MAX_LEN 1505
#define MAX_Q   100005

int main() {
    int H, W, Q;
    int X[MAX_LEN][MAX_LEN], Z[MAX_LEN][MAX_LEN];
    int A[MAX_Q], B[MAX_Q], C[MAX_Q], D[MAX_Q];
    int Answer[MAX_Q];

    // 入力
    scanf("%d%d", &H, &W);
    for (int row = 1; row <= H; row++) {
        for (int col = 1; col <= W; col++) {
            scanf("%d", &X[row][col]);
        }
    }
    scanf("%d", &Q);
    for (int num_q = 1; num_q <= Q; num_q++) {
        scanf("%d%d%d%d", &A[num_q], &B[num_q], &C[num_q], &D[num_q]);
    }

    // 初期化
    for (int r = 0; r <= H; r++) {
        for (int c = 0; c <= W; c++) {
            Z[r][c] = 0;
        }
    }
    // 2次元累積和
    for (int row = 1; row <= H; row++) {
        // col方向の累積和
        for (int col = 1; col <= W; col++) {
            Z[row][col] = X[row][col] + Z[row][col - 1];
        }
        // row方向の累積和
        for (int col = 1; col <= W; col++) {
            Z[row][col] = Z[row - 1][col] + Z[row][col];
        }
    }

    // 計算
    for (int que = 1; que <= Q; que++) {
        Answer[que] = Z[A[que] - 1][B[que] - 1] + Z[C[que]][D[que]]
                      - Z[A[que] - 1][D[que]] - Z[C[que]][B[que] - 1];
    }

    // 出力
    for (int i = 1; i <= Q; i++) {
        printf("%d\n", Answer[i]);
    }
}