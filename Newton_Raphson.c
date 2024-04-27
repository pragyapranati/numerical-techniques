#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6

double evaluatePolynomial(double x, int degree, double coefficients[]) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

double evaluatePolynomialDerivative(double x, int degree, double coefficients[]) {
    double result = 0;
    for (int i = 0; i < degree; i++) {
        result += (degree - i) * coefficients[i] * pow(x, degree - i - 1);
    }
    return result;
}

double newtonRaphson(int degree, double coefficients[], double x0, int max_iterations) {
    double x = x0; 
    int iterations = 0;

    while (iterations < max_iterations) {
        double fx = evaluatePolynomial(x, degree, coefficients);
        double dfx = evaluatePolynomialDerivative(x, degree, coefficients);
        double x_new = x - fx / dfx;

        printf("Iteration %d:\n", iterations + 1);
        printf("x%d = %.6f\n", iterations, x);
        printf("f(x%d) = %.6f\n", iterations, fx);
        printf("f'(x%d) = %.6f\n", iterations, dfx);

        if (fabs(x_new - x) < EPSILON) {
            return x_new;
        }

        x = x_new;
        iterations++;
    }

    return x;
}

int main() {
    int degree, max_iterations;
    printf("Enter the highest degree of the polynomial: ");
    scanf("%d", &degree);

    double coefficients[degree + 1];

    printf("Enter the coefficients of the polynomial (starting from highest degree to constant term):\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient for x^%d: ", degree - i);
        scanf("%lf", &coefficients[i]);
    }

    double initial_guess;
    printf("Enter your initial guess (x0): ");
    scanf("%lf", &initial_guess);

    printf("Enter the number of iterations: ");
    scanf("%d", &max_iterations);

    double root = newtonRaphson(degree, coefficients, initial_guess, max_iterations);

    printf("Root found at: %.6f\n", root);

    return 0;
}
