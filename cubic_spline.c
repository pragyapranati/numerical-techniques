#include <stdio.h>
#include <stdlib.h>
double calculateStirlingInterpolation(double x, double* xVals, double* yVals, int numPoints, double h);

int main() {
    int numPoints;
    printf("Enter the number of data points: ");
    scanf("%d", &numPoints);
    double* xVals = (double*)malloc(numPoints * sizeof(double));
    double* yVals = (double*)malloc(numPoints * sizeof(double));
    printf("Enter x and y coordinates of each point:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &xVals[i], &yVals[i]);
    }
    double h;
    printf("\nEnter the increment h: ");
    scanf("%lf", &h);
    double x;
    printf("Enter x for interpolation: ");
    scanf("%lf", &x);
    double interpolatedValue = calculateStirlingInterpolation(x, xVals, yVals, numPoints, h);
    printf("Interpolated value at x = %.2f: %.6f\n", x, interpolatedValue);
    free(xVals);
    free(yVals);

    return 0;
}

double calculateStirlingInterpolation(double x, double* xVals, double* yVals, int numPoints, double h) {
    double result = 0;
    int k = 0;
    while (x > xVals[k + 1] && k < numPoints - 1) {
        k++;
    }
    double* centralDifferences = (double*)malloc((numPoints - 1) * sizeof(double));
    for (int i = 0; i < numPoints - 1; i++) {
        centralDifferences[i] = yVals[i + 1] - yVals[i];
    }

    double f0 = yVals[k];
    double f1 = centralDifferences[k];
    double f2 = 0.0;
    double f3 = 0.0;

    if (k > 0) {
        f2 = (centralDifferences[k] - centralDifferences[k - 1]) / h;
        f3 = (centralDifferences[k] - 2 * centralDifferences[k - 1] + centralDifferences[k - 2]) / (2 * h * h);
    }

    result = f0 + (x - xVals[k]) * f1 + (x - xVals[k]) * (x - xVals[k] - h) * f2 / 2 + (x - xVals[k]) * (x - xVals[k] - h) * (x - xVals[k] - 2 * h) * f3 / 6;
    free(centralDifferences);

    return result;
}
