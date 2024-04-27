#include <stdio.h>
#include <math.h>

// Define the function f(x, y)
double f(double x, double y) {
    // Define your function here, for example:
    // return x * y;
    // or any other function of x and y
}

// Bashforth method for numerical integration
double bashforth(double (*func)(double, double), double x0, double y0, double h, int steps) {
    double y = y0;
    double x = x0;

    for (int i = 0; i < steps; i++) {
        double k1 = h * func(x, y);
        double k2 = h * func(x + h / 2, y + k1 / 2);
        double k3 = h * func(x + h / 2, y + k2 / 2);
        double k4 = h * func(x + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;
    }

    return y;
}

int main() {
    // Input initial conditions
    double x0, y0;
    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y: ");
    scanf("%lf", &y0);

    // Input step size
    double h;
    printf("Enter the step size (h): ");
    scanf("%lf", &h);

    // Input number of steps
    int steps;
    printf("Enter the number of steps: ");
    scanf("%d", &steps);

    // Perform integration
    double result = bashforth(f, x0, y0, h, steps);

    printf("Result of integration: %.6f\n", result);

    return 0;
}
