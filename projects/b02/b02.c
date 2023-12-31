#include <stdio.h>

int main(void) {
    int a, b, i;
    scanf("%d %d", &a, &b);

    for (i = a; i <= b; i++) {
        if (100 % i == 0) {
            printf("Yes\n");
            exit(0);
        }
    }
    printf("No\n");

    return 0;
}