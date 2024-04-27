#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the function f(x, y)
double f(double x, double y) {
    // Define your function here, for example:
    // return x * y;
    // or any other function of x and y
}

// Trapezoidal method for integration
double trapezoidal(double (*func)(double, double), double x0, double xn, double y, int n) {
    double h = (xn - x0) / n;
    double sum = 0.5 * (func(x0, y) + func(xn, y));

    for (int i = 1; i < n; i++) {
        double x = x0 + i * h;
        sum += func(x, y);
    }

    return sum * h;
}

int main() {
    // Input the dy/dx equation as a string
    char equation[100];
    printf("Enter the dy/dx equation in terms of x and y: ");
    fgets(equation, sizeof(equation), stdin);

    // Input integration range
    double x0, xn;
    printf("Enter the lower limit of x: ");
    scanf("%lf", &x0);
    printf("Enter the upper limit of x: ");
    scanf("%lf", &xn);

    // Input number of divisions
    int n;
    printf("Enter the number of divisions: ");
    scanf("%d", &n);

    // Perform integration
    double result = 0.0;
    for (double x = x0; x < xn; x += 0.01) {
        // Evaluate the function y at each x using the equation
        // This assumes that y = dy/dx * dx
        double y = atof(equation) * 0.01;
        result += trapezoidal(f, x, x + 0.01, y, n);
    }

    printf("Result of integration: %.6f\n", result);

    return 0;
}
