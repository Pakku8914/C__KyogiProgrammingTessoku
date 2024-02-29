#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define MAX_N     100005

int main() {
    int N;
    int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
    int field[1505][1505];
    int max_x = 0, max_y = 0;
    int ans_cnt = 0;

    // 入力
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
        max_x = max(max_x, C[i]);
        max_y = max(max_y, D[i]);
    }

    // 初期化
    for (int i = 0; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) {
            field[i][j] = 0;
        }
    }

    // 代入
    for (int i = 1; i <= N; i++) {
        field[A[i] + 1][B[i] + 1]++;
        field[A[i] + 1][D[i] + 1]--;
        field[C[i] + 1][B[i] + 1]--;
        field[C[i] + 1][D[i] + 1]++;
    }

    // 累積和計算
    for (int i = 1; i <= max_x; i++) {
        // 横方向
        for (int j = 1; j <= max_y; j++) {
            field[i][j] = field[i][j] + field[i][j - 1];
        }
        // 縦方向
        for (int j = 1; j <= max_y; j++) {
            field[i][j] = field[i - 1][j] + field[i][j];
        }
    }

    for (int i = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {
            if (field[i][j]) ans_cnt++;
        }
    }

    printf("%d\n", ans_cnt);
}