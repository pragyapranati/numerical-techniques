#include <stdio.h>
#include <math.h>

void printMatrix(double A[][100], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%.4f\t", A[i][j]);
        }
        printf("\n");
    }
}

void qrDecomposition(double A[][100], double Q[][100], double R[][100], int rows, int cols) {
    double temp[100][100] = {0};
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            temp[i][j] = A[i][j];
        }
    }

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < j; i++) {
            double dot_product = 0;
            for (int k = 0; k < rows; k++) {
                dot_product += Q[k][i] * temp[k][j];
            }
            for (int k = 0; k < rows; k++) {
                temp[k][j] -= dot_product * Q[k][i];
            }
        }

        double norm = 0;
        for (int i = 0; i < rows; i++) {
            norm += temp[i][j] * temp[i][j];
        }
        norm = sqrt(norm);

        for (int i = 0; i < rows; i++) {
            Q[i][j] = temp[i][j] / norm;
        }

        for (int i = 0; i < cols; i++) {
            double dot_product = 0;
            for (int k = 0; k < rows; k++) {
                dot_product += Q[k][j] * A[k][i];
            }
            R[j][i] = dot_product;
        }
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    double A[100][100], Q[100][100] = {0}, R[100][100] = {0};

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    qrDecomposition(A, Q, R, rows, cols);

    printf("Matrix Q:\n");
    printMatrix(Q, rows, cols);

    printf("\nMatrix R:\n");
    printMatrix(R, cols, cols);

    return 0;
}
