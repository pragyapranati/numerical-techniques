#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
double newtonForwardInterpolation(double x, int n, double X[], double Y[]) {
    double result = 0;
    double h = X[1] - X[0];
    double u = (x - X[0]) / h;

    double F[n][n];
    for (int i = 0; i < n; i++) {
        F[i][0] = Y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            F[j][i] = F[j + 1][i - 1] - F[j][i - 1];
        }
    }

    result = F[0][0];
    for (int i = 1; i < n; i++) {
        double term = F[0][i];
        for (int j = 0; j < i; j++) {
            term *= (u - j);
            term /= (j + 1);
        }
        result += term;
    }

    return result;
}

double newtonBackwardInterpolation(double x, int n, double X[], double Y[]) {
    double result = 0;
    double h = X[1] - X[0];
    double u = (x - X[n - 1]) / h;
    double B[n][n];
    for (int i = 0; i < n; i++) {
        B[i][0] = Y[n - i - 1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            B[j][i] = B[j + 1][i - 1] - B[j][i - 1];
        }
    }

    result = B[0][0];
    for (int i = 1; i < n; i++) {
        double term = B[0][i];
        for (int j = 0; j < i; j++) {
            term *= (u + j);
            term /= (j + 1);
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double X[n], Y[n];
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &X[i], &Y[i]);
    }

    double x;
    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x);

    double forwardResult = newtonForwardInterpolation(x, n, X, Y);
    printf("Interpolated value using Newton's forward interpolation: %lf\n", forwardResult);

    double backwardResult = newtonBackwardInterpolation(x, n, X, Y);
    printf("Interpolated value using Newton's backward interpolation: %lf\n", backwardResult);

    return 0;
}