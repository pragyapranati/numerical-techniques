#include <stdio.h>
#include <math.h>

// Function to integrate
double f(double x) {
    return x * x;  // Example function x^2, replace with your own function
}

// Simpson's 1/3 rule for 1-variable function
double simpsons_13_1d(double *x, double *fx, int n) {
    double h = x[1] - x[0];
    double approx = fx[0] + fx[n-1];
    
    for (int i = 1; i < n-1; i++) {
        if (i % 2 == 1) {
            approx += 4 * fx[i];
        } else {
            approx += 2 * fx[i];
        }
    }

    approx *= h / 3.0;

    return approx;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], fx[n];

    printf("Enter the x and f(x) values:\n");
    printf("x\tf(x)\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &fx[i]);
    }

    double result = simpsons_13_1d(x, fx, n);
    printf("Approximated integral: %lf\n", result);

    return 0;
}
