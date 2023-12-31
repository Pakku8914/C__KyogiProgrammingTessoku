#include <stdio.h>

#define MAX_N 101

int main(void) {
    int n, x, loop_cnt;
    int a[MAX_N];

    scanf("%d %d", &n, &x);
    for (loop_cnt = 1; loop_cnt <= n; loop_cnt++) {
        scanf("%d", a + loop_cnt);
    }

    // 全探索(1 ~ 100)
    for (loop_cnt = 1; loop_cnt <= n; loop_cnt++) {
        if (a[loop_cnt] == x) {
            printf("Yes\n");
            exit(0);
        }
    }
    printf("No\n");
}