#include <stdio.h>
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

void dividedDifferences(double x[], double y[], int n, double dd[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

double computeFX(double x[], double dd[][4], int n, double value) {
    double result = 0;
    double term = 1;

    for (int i = 0; i < n; i++) {
        double product = 1;
        for (int j = 0; j < i; j++) {
            product *= (value - x[j]);
        }
        result += dd[0][i] * product;
    }

    return result;
}

double computeDerivative(double x[], double dd[][4], int n, double value) {
    double result = 0;

    for (int i = 0; i < n - 1; i++) {
        double term = dd[0][i];
        for (int j = 0; j < i; j++) {
            term *= (value - x[j]);
        }
        result += term * (i + 1) / factorial(i + 1);
    }

    return result;
}

double computeSecondDerivative(double x[], double dd[][4], int n, double value) {
    double result = 0;

    for (int i = 0; i < n - 2; i++) {
        double term = dd[0][i];
        for (int j = 0; j < i; j++) {
            term *= (value - x[j]);
        }
        result += term * (i + 1) * (i + 2) / factorial(i + 1);
    }

    return result;
}

int main() {
    int n; 
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    double dd[n][n];
    dividedDifferences(x, y, n, dd);
    double value;
    printf("\nEnter the value at which you want to find f(x): ");
    scanf("%lf", &value);

    double fx = computeFX(x, dd, n, value);
    double derivative = computeDerivative(x, dd, n, value);
    double secondDerivative = computeSecondDerivative(x, dd, n, value);
    printf("\nf(%lf) = %lf\n", value, fx);
    printf("f'(%lf) = %lf\n", value, derivative);
    printf("f''(%lf) = %lf\n", value, secondDerivative);

    return 0;
}
