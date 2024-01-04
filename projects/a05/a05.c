#include <stdio.h>

int main(void) {
    int n, k;
    int ans = 0;
    scanf("%d %d", &n, &k);

    for (int x = 1; x <= n && x <= n; x++) {
        for (int y = 1; y <= n && y <= n; y++) {
            int z = k - x - y;
            if (1 <= z && z <= n) ans++;
        }
    }

    printf("%d\n", ans);
}