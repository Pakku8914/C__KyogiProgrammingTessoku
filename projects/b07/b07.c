// #include <stdio.h>

// #define MAX_N 500005
// #define MAX_T 500005

// int main() {
//     int T;
//     int N;
//     int L[MAX_N], R[MAX_N];
//     int Answer[MAX_T], B[MAX_T];

//     // 入力
//     scanf("%d%d", &T, &N);
//     for (int i = 0; i < N; i++) {
//         scanf("%d%d", &L[i], &R[i]);
//     }

//     // 配列準備
//     for (int i = 0; i <= T; i++)
//         B[i] = 0;

//     // 代入
//     for (int i = 0; i < N; i++) {
//         B[L[i]]++;
//         B[R[i]]--;
//     }

//     // 累積和
//     Answer[0] = B[0];
//     for (int i = 1; i <= T; i++) {
//         Answer[i] = Answer[i - 1] + B[i];
//     }

//     // 出力
//     for (int i = 0; i <= T - 1; i++) {
//         printf("%d\n", Answer[i]);
//     }
// }
#include <stdio.h>

#define MAX_N 500005
#define MAX_T 500005

int main() {
    int T;                  // 時間
    int N;                  // 人数
    int L[MAX_N], R[MAX_N]; // 出勤時間：退勤時間
    int jobs[MAX_T];        // 就業人数

    // 入力
    scanf("%d%d", &T, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &L[i], &R[i]);
    }

    // 初期化
    for (int i = 0; i <= T; i++) {
        jobs[i] = 0;
    }
    // 代入
    for (int i = 0; i < N; i++) {
        jobs[L[i]]++;
        jobs[R[i]]--;
    }

    // 累積和
    for (int i = 1; i <= T; i++) {
        jobs[i] = jobs[i] + jobs[i - 1];
    }

    // 出力
    for (int i = 0; i <= T - 1; i++) {
        printf("%d\n", jobs[i]);
    }
}