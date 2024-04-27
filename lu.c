#include <stdio.h>

#define MAX_SIZE 10

void printMatrix(double A[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
}

void luFactorization(double A[MAX_SIZE][MAX_SIZE], double L[MAX_SIZE][MAX_SIZE], double U[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                L[i][j] = 1.0;
            else
                L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int j = k; j < n; j++) {
            U[k][j] = A[k][j];
            for (int p = 0; p < k; p++) {
                U[k][j] -= L[k][p] * U[p][j];
            }
        }
        for (int i = k + 1; i < n; i++) {
            L[i][k] = A[i][k];
            for (int p = 0; p < k; p++) {
                L[i][k] -= L[i][p] * U[p][k];
            }
            L[i][k] /= U[k][k];
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the square matrix (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid matrix size. Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    double A[MAX_SIZE][MAX_SIZE], L[MAX_SIZE][MAX_SIZE], U[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    luFactorization(A, L, U, n);

    printf("\nMatrix A:\n");
    printMatrix(A, n);

    printf("\nMatrix L:\n");
    printMatrix(L, n);

    printf("\nMatrix U:\n");
    printMatrix(U, n);

    return 0;
}
