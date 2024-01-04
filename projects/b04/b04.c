#include <stdio.h>

int main(void) {
    int N;
    int sum = 0;
    int i   = 0;
    int remainder;
    scanf("%d", &N);

    while (N != 0) {
        // 1の位だけ取り出す
        remainder = N % 10;
        // 10の位以上を取り出す
        N /= 10;
        sum += remainder * (1 << i);
        i++;
    }

    printf("%d\n", sum);
}