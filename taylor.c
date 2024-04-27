#include <stdio.h>
#include <math.h>

// Define the function f(x, y)
double f(double x, double y) {
    // Define your function here, for example:
    // return x * y;
    // or any other function of x and y
}

// Compute the factorial of n
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Taylor series method for numerical integration
double taylor(double (*func)(double, double), double x0, double y0, double h, int steps) {
    double y = y0;
    double x = x0;

    for (int i = 0; i < steps; i++) {
        double slope = func(x, y);
        double increment = h * slope;
        
        // Taylor series expansion for y
        for (int j = 2; j <= 4; j++) {
            increment += (pow(h, j) / factorial(j)) * (func(x, y) * pow(h, j - 1));
        }

        y += increment;
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
    double result = taylor(f, x0, y0, h, steps);

    printf("Result of integration: %.6f\n", result);

    return 0;
}
