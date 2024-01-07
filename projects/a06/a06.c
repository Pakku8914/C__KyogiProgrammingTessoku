#include <stdio.h>

#define max_n 100001

int main() {
    int n, q;
    int a[max_n];

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 累積和計算
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] + a[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", a[r] - a[l - 1]);
    }

    return 0;
}