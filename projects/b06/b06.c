#include <stdio.h>

#define max_nq 100001

int main() {
    int n;
    int a[max_nq];
    int q;
    int l[max_nq], r[max_nq];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 1; 1 <= q; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }

    // 累積和
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] + a[i - 1];
    }

    for (int i = 1; i <= q; i++) {
        if (a[r[i]] - a[l[i] - 1] == (r[i] - l[i] + 1) / 2) {
            printf("draw\n");
        }
        else if (a[r[i]] - a[l[i] - 1] > (r[i] - l[i] + 1) / 2) {
            printf("win\n");
        }
        else {
            printf("lose\n");
        }
    }
}