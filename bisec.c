#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 10
double function(double x, int degree, double coefficients[]) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}
double bisection(double a, double b, int degree, double coefficients[]) {
    double c, fc;
    if (function(a, degree, coefficients) * function(b, degree, coefficients) > 0) {
        printf("Initial guesses do not bracket the root.\n");
        return NAN;
    }
    do {
        c = (a + b) / 2;
        fc = function(c, degree, coefficients);
        if (fc == 0) {
            return c; 
        }
        if (function(a, degree, coefficients) * fc < 0) {
            b = c; 
        } else {
            a = c;
        }
    } while (1);
}

int main() {
    int degree;
    double coefficients[MAX_DEGREE + 1];
    double a, b, root;
    printf("Enter the degree of the polynomial (max degree is %d): ", MAX_DEGREE);
    scanf("%d", &degree);
    printf("Enter the coefficients of the polynomial (from highest degree to constant term):\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%lf", &coefficients[i]);
    }
    printf("Enter initial guess for a: ");
    scanf("%lf", &a);
    printf("Enter initial guess for b: ");
    scanf("%lf", &b);
    root = bisection(a, b, degree, coefficients);
    if (!isnan(root)) {
        printf("Root found at: %lf\n", root);
    }

    return 0;
}
