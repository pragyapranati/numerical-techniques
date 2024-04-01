#include <stdio.h>

void jacobiMethod(int n, double A[n][n], double b[n], double x[n], int maxIter) {
    double tempX[n];

    for (int iter = 0; iter < maxIter; iter++) {
        for (int i = 0; i < n; i++) {
            tempX[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    tempX[i] -= A[i][j] * x[j];
                }
            }
            tempX[i] /= A[i][i];
        }

        for (int i = 0; i < n; i++) {
            x[i] = tempX[i];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the system of equations: ");
    scanf("%d", &n);

    double A[n][n];
    double b[n];
    double x[n];
    int maxIter;

    printf("Enter the coefficients of the matrix A:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the constants of the right-hand side vector b:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%lf", &b[i]);
    }

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIter);
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    jacobiMethod(n, A, b, x, maxIter);

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i + 1, x[i]);
    }

    return 0;
}
