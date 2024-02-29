#include <stdio.h>

#define MAX_N 100005
#define MAX_D 100005

#define max(a, b) (a > b ? a : b)

int main() {
    int N;
    int A[MAX_N], right_max[MAX_N], left_max[MAX_N];
    int D;
    int L[MAX_D], R[MAX_D];

    // 入力
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &D);
    for (int i = 1; i <= D; i++) {
        scanf("%d%d", &L[i], &R[i]);
    }

    // 初期化
    for (int i = 0; i <= N; i++) {
        right_max[i] = 0;
        left_max[i]  = 0;
    }
    // 最大値配列準備
    for (int i = 1; i <= N; i++) {
        right_max[i] = max(right_max[i - 1], A[i]);
    }
    for (int i = N; 1 <= i; i--) {
        left_max[i] = max(left_max[i + 1], A[i]);
    }

    // 出力
    for (int i = 1; i <= D; i++) {
        printf("%d\n", max(right_max[L[i] - 1], left_max[R[i] + 1]));
    }
}
