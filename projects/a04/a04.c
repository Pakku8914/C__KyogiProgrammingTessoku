#include <math.h>
#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 9; i >= 0; i--) {
        int dis = pow(2, i);
        printf("%d", (N / dis) % 2);
    }
    printf("\n");
}