#include <stdio.h>

#define MAX_N 101

int main(void) {
    int N;
    int A[MAX_N];

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", A + i);
    }

    for (int x = 1; x <= N; x++) {
        for (int y = x + 1; y <= N; y++) {
            for (int z = y + 1; z <= N; z++) {
                if (A[x] + A[y] + A[z] == 1000) {
                    printf("Yes\n");
                    exit(0);
                }
            }
        }
    }
    printf("No\n");

    return 0;
}