#include <stdio.h>

#define MAX_D 100005
#define MAX_N 100005

int main() {
    // 変数
    int D;
    int N;
    int L[MAX_N], R[MAX_N];
    int cul[MAX_D];

    // 入力
    scanf("%d%d", &D, &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &L[i], &R[i]);
    }

    // 計算
    for (int i = 1; i <= N; i++) {
        // 出席日に人数インクリメント
        cul[L[i]]++;
        // 退席日に人数デクリメント
        cul[R[i] + 1]--;
    }

    // 累積和計算
    for (int i = 1; i <= D; i++) {
        cul[i] = cul[i] + cul[i - 1];
    }

    // 出力
    for (int i = 1; i <= D; i++) {
        printf("%d\n", cul[i]);
    }

    return 0;
}