#include <stdio.h>

#define MAX_N 100005
#define MAX_Q 100005

void swap(int *left, int *right) {
    int temp = *left;
    *left    = *right;
    *right   = temp;
}

void bubble_sort(int N, int *A) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int main(void) {
    int N;
    int A[MAX_N];
    int Q;
    int X[MAX_Q];

    // 入力
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d", &X[i]);
    }

    // 整列
    bubble_sort(N, A);

    for (int que_num = 1; que_num <= Q; que_num++) {
        // binary search
        for (int left = 1, right = N; left != right;) {
            int mid = (left + right) / 2;

            if (X[que_num] < A[mid]) {
                right = mid;
            }
            if (A[mid] < X[que_num]) {
                left = mid;
            }
            if (A[mid] == X[que_num]) {
                right = mid;
                left  = mid;
            }
        }
    }
}