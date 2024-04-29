#include <stdio.h>

#define MAX_N 100005

int main(void) {
    int N, X;
    int A[MAX_N];
    int left, right;

    // input
    scanf("%d%d", &N, &X);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    // binary search
    for (left = 1, right = N; left != right;) {
        int mid = (left + right) / 2;

        if (A[mid] > X) {
            right = mid - 1;
        }
        if (A[mid] < X) {
            left = mid + 1;
        }
        if (A[mid] == X) {
            right = mid;
            left  = mid;
        }
    }
    printf("%d\n", right);

    return 0;
}