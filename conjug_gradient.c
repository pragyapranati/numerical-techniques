#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10

void conjugateGradient(double A[][MAX_SIZE], double b[], double x[], int n, int maxIterations);

int main() {
    int n, i, j;
    double A[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], x[MAX_SIZE];
    int maxIterations;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Invalid matrix size.\n");
        return 1;
    }

    printf("Enter the elements of the matrix A row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%lf", &A[i][j]) != 1) {
                printf("Error: Invalid input for matrix element.\n");
                return 1;
            }
        }
    }

    printf("Enter the elements of the vector b:\n");
    for (i = 0; i < n; i++) {
        if (scanf("%lf", &b[i]) != 1) {
            printf("Error: Invalid input for vector element.\n");
            return 1;
        }
    }

    printf("Enter the initial guess for x:\n");
    for (i = 0; i < n; i++) {
        if (scanf("%lf", &x[i]) != 1) {
            printf("Error: Invalid input for initial guess.\n");
            return 1;
        }
    }

    printf("Enter the maximum number of iterations: ");
    if (scanf("%d", &maxIterations) != 1 || maxIterations <= 0) {
        printf("Error: Invalid input for maximum iterations.\n");
        return 1;
    }

    conjugateGradient(A, b, x, n, maxIterations);

    printf("\nThe solution vector x is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }

    return 0;
}

void conjugateGradient(double A[][MAX_SIZE], double b[], double x[], int n, int maxIterations) {
    double r[MAX_SIZE], p[MAX_SIZE], Ap[MAX_SIZE];
    double alpha, beta, rDotR, rDotRNew;
    int i, j, k;

    for (i = 0; i < n; i++) {
        r[i] = b[i];
        for (j = 0; j < n; j++) {
            r[i] -= A[i][j] * x[j];
        }
        p[i] = r[i];
    }

    for (k = 0; k < maxIterations; k++) {
        for (i = 0; i < n; i++) {
            Ap[i] = 0.0;
            for (j = 0; j < n; j++) {
                Ap[i] += A[i][j] * p[j];
            }
        }

        rDotR = 0.0;
        for (i = 0; i < n; i++) {
            rDotR += r[i] * r[i];
        }

        double pDotAp = 0.0;
        for (i = 0; i < n; i++) {
            pDotAp += p[i] * Ap[i];
        }

        alpha = rDotR / pDotAp;

        for (i = 0; i < n; i++) {
            x[i] += alpha * p[i];
        }

        for (i = 0; i < n; i++) {
            r[i] -= alpha * Ap[i];
        }

        rDotRNew = 0.0;
        for (i = 0; i < n; i++) {
            rDotRNew += r[i] * r[i];
        }

        beta = rDotRNew / rDotR;

        for (i = 0; i < n; i++) {
            p[i] = r[i] + beta * p[i];
        }

        rDotR = rDotRNew;
    }
}
