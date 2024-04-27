#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void multiplyMatrixVector(double **matrix, double *vector, double *result, int size) 
{
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

double maxAbs(double *vector, int size) 
{
    double max = fabs(vector[0]);
    for (int i = 1; i < size; i++) {
        if (fabs(vector[i]) > max) {
            max = fabs(vector[i]);
        }
    }
    return max;
}

int main() {
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    double **matrix = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
    }
    

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double *initialVector = (double *)malloc(size * sizeof(double));
    printf("Enter the initial vector:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &initialVector[i]);
    }

    double *resultVector = (double *)malloc(size * sizeof(double));
    double lambda = 0;
    double epsilon = 1e-6; 
    int maxIterations = 1000;
    int iterations = 0;

    do {
        multiplyMatrixVector(matrix, initialVector, resultVector, size);

       
        double norm = maxAbs(resultVector, size);
        for (int i = 0; i < size; i++) {
            resultVector[i] /= norm;
        }

        
        lambda = maxAbs(resultVector, size);

        
        for (int i = 0; i < size; i++) {
            initialVector[i] = resultVector[i];
        }

        iterations++;
    } while (iterations < maxIterations && fabs(lambda - maxAbs(initialVector, size)) > epsilon);

    if (iterations == maxIterations) {
        printf("Power method did not converge within the specified number of iterations.\n");
    } else {
        printf("Eigenvalue approximation: %lf\n", lambda);
        printf("Eigenvector approximation:\n");
        for (int i = 0; i < size; i++) {
            printf("%lf\n", initialVector[i]);
        }
    }

    
    for (int i = 0; i < size; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
    free(initialVector);
    free(resultVector);

    return 0;
}
