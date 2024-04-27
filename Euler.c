#include <stdio.h>
#include <math.h>

// Function to compute the derivative dy/dx = f(x, y)
double derivative(double (*f)(double, double), double x, double y) {
    return f(x, y);
}

// Euler's method
double euler(double (*f)(double, double), double x0, double y0, double h, double target_x) {
    int steps = (int)(target_x / h);  // Calculate the number of steps
    double x = x0, y = y0;

    for (int i = 0; i < steps; i++) {
        y += h * derivative(f, x, y);
        x += h;
    }

    return y;
}

// User-defined function f(x, y) (example: -2x - y)
double user_function(double x, double y) {
    return -2 * x - y;
}

int main() {
    double x0, y0, h, target_x;

    // Get initial conditions from user
    printf("Enter initial value x0: ");
    scanf("%lf", &x0);
    
    printf("Enter initial value y0: ");
    scanf("%lf", &y0);

    // Get step length from user
    printf("Enter step length h: ");
    scanf("%lf", &h);

    // Get target x value from user
    printf("Enter target x value: ");
    scanf("%lf", &target_x);

    double result = euler(user_function, x0, y0, h, target_x);
    
    printf("\nUsing Euler's method:\n");
    printf("y(%.4lf) = %.4lf\n", target_x, result);

    return 0;
}
