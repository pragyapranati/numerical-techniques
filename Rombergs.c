#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * sin(x);
}

// Composite trapezoidal rule
double trapezoidal(double (*f)(double), double a, double b, int n) 
{
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        sum += f(xi);
    }

    return h * (0.5 * (f(a) + f(b)) + sum);
}


double romberg(double (*f)(double), double a, double b, int n) 
{
    double R[n][n];

    
    for (int i = 0; i < n; i++) {
        R[i][0] = trapezoidal(f, a, b, pow(2, i));
    }

    
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    return R[n-1][n-1];
}

int main() {
    double a = 0, b = M_PI;  
    int n_values[] = {1, 2, 4, 8};  
    int n_values_count = sizeof(n_values) / sizeof(n_values[0]);

    printf("Using composite trapezoidal rule:\n");
    for (int i = 0; i < n_values_count; i++) {
        double result = trapezoidal(f, a, b, n_values[i]);
        printf("n = %d, Approximated integral: %.3lf\n", n_values[i], result);
    }

    printf("\nUsing Romberg's method:\n");
    for (int i = 0; i < n_values_count; i++) {
        double result = romberg(f, a, b, n_values[i]);
        printf("n = %d, Approximated integral: %.3lf\n", n_values[i], result);
    }

    return 0;
}
