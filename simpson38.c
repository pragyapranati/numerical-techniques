#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x) {
   
}


double simpson_3_8(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    return (3 * h / 8) * sum;
}

int main() {
    // Input integration range
    double a, b;
    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);

    // Input number of divisions (must be a multiple of 3)
    int n;
    printf("Enter the number of divisions (must be a multiple of 3): ");
    scanf("%d", &n);

    // Check if n is a multiple of 3
    if (n % 3 != 0) {
        printf("Error: Number of divisions must be a multiple of 3.\n");
        return 1;
    }

    // Perform integration
    double result = simpson_3_8(f, a, b, n);

    printf("Result of integration: %.6f\n", result);

    return 0;
}



#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the function f(x, y)
double f(double x, double y) {
    // Define your function here, for example:
    // return x * y;
    // or any other function of x and y
}

// Simpson's 3/8 rule for integration
double simpson_3_8(double (*func)(double, double), double x0, double xn, double y0, double yn, int n) {
    double hx = (xn - x0) / n;
    double hy = (yn - y0) / n;
    double sum = f(x0, y0) + f(xn, yn);

    for (int i = 1; i < n; i++) {
        double x = x0 + i * hx;
        double y = y0 + i * hy;
        if (i % 3 == 0)
            sum += 2 * f(x, y);
        else
            sum += 3 * f(x, y);
    }

    return (3 * hx * hy / 8) * sum;
}

int main() {
    // Input integration range
    double x0, xn, y0, yn;
    printf("Enter the lower limit of x: ");
    scanf("%lf", &x0);
    printf("Enter the upper limit of x: ");
    scanf("%lf", &xn);
    printf("Enter the lower limit of y: ");
    scanf("%lf", &y0);
    printf("Enter the upper limit of y: ");
    scanf("%lf", &yn);

    // Input number of divisions (must be a multiple of 3)
    int n;
    printf("Enter the number of divisions (must be a multiple of 3): ");
    scanf("%d", &n);

    // Check if n is a multiple of 3
    if (n % 3 != 0) {
        printf("Error: Number of divisions must be a multiple of 3.\n");
        return 1;
    }

    // Perform integration
    double result = simpson_3_8(f, x0, xn, y0, yn, n);

    printf("Result of integration: %.6f\n", result);

    return 0;
}

