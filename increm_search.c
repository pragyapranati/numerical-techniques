#include <stdio.h>
#include <math.h>

double evaluatePolynomial(double x, int degree, double coefficients[]) {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

void incrementalSearch(double a, double b, double step, int degree, double coefficients[]) {
    double x, yA, yB;

    printf("Incremental Search Method\n");

    for (x = a; x <= b; x += step) {
        yA = evaluatePolynomial(x, degree, coefficients);
        yB = evaluatePolynomial(x + step, degree, coefficients);

        if (yA * yB <= 0) {
            printf("Root found in the interval [%.2lf, %.2lf]\n", x, x + step);
        }
    }
}

int main() {
    double a, b, step;
    int degree;
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the degree of the polynomial function: ");
    scanf("%d", &degree);

    double coefficients[degree + 1];
    printf("Enter the coefficients of the polynomial function (from highest to lowest degree):\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%lf", &coefficients[i]);
    }

    printf("Enter the step size: ");
    scanf("%lf", &step);
    incrementalSearch(a, b, step, degree, coefficients);

    return 0;
}
