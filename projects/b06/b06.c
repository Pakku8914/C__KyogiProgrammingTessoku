#include <stdio.h>

#define max_nq 100001

int main() {
    int n;
    int a[max_nq];
    int q;
    int l[max_nq], r[max_nq];
    int Atari[max_nq], Hazre[max_nq];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }

    // 累積和
    for (int i = 1; i <= n; i++) {
        Atari[i] = Atari[i - 1];
        Hazre[i] = Hazre[i - 1];
        if (a[i] == 1) Atari[i] += 1;
        if (a[i] == 0) Hazre[i] += 1;
    }

    for (int i = 1; i <= q; i++) {
        int difAtari = Atari[r[i]] - Atari[l[i] - 1];
        int difHazre = Hazre[r[i]] - Hazre[l[i] - 1];
        if (difAtari > difHazre) printf("win\n");
        else if (difAtari == difHazre) printf("draw\n");
        else printf("lose\n");
    }

    return 0;
}
