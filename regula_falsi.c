#include <stdio.h>
#include <math.h>

// Function to evaluate the polynomial
double f(double coefficients[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

// Regula Falsi method to find the root
double regulaFalsi(double coefficients[], int degree, double a, double b, int maxIterations) {
    double c;
    for (int i = 0; i < maxIterations; i++) {
        // Calculate c using Regula Falsi method
        c = (a * f(coefficients, degree, b) - b * f(coefficients, degree, a)) / (f(coefficients, degree, b) - f(coefficients, degree, a));

        // Update the interval [a, b]
        if (f(coefficients, degree, c) * f(coefficients, degree, a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    double coefficients[degree + 1];
    printf("Enter the coefficients of the polynomial starting from the highest degree term:\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%lf", &coefficients[i]);
    }

    double a, b;
    printf("Enter the initial interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    int maxIterations;
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    double root = regulaFalsi(coefficients, degree, a, b, maxIterations);
    printf("Approximate root: %lf\n", root);

    return 0;
}
