#include <stdio.h>

// Function to compute the derivative y'
double derivative(double x, double y) 
{
    return (x + y) / 2.0;
}

// Adams-Bashforth Predictor
double adams_bashforth_predictor(double yn, double yn_1, double yn_2, double yn_3, double h) {
    return yn + h / 24.0 * (55 * derivative(1.5, yn) - 59 * derivative(1.0, yn_1) + 37 * derivative(0.5, yn_2) - 9 * derivative(0.0, yn_3));
}

// Adams-Bashforth Corrector
double adams_bashforth_corrector(double yn, double yn_1, double yn_2, double yn_3, double ynp, double h) 
{
    return yn + h / 24.0 * (9 * derivative(2.0, ynp) + 19 * derivative(1.5, yn) - 5 * derivative(1.0, yn_1) + derivative(0.5, yn_2));
}

int main() {
    double x[4];
    double y[4];
    double h;

    // Input values
    printf("Enter the values of x and y:\n");
    for (int i = 0; i < 4; i++) {
        printf("x%d: ", i);
        scanf("%lf", &x[i]);
        printf("y%d: ", i);
        scanf("%lf", &y[i]);
    }

    // Input step size
    printf("Enter the step size (h): ");
    scanf("%lf", &h);
    
    // Predictor
    double ynp = adams_bashforth_predictor(y[3], y[2], y[1], y[0], h);
    
    printf("Predicted y(2) = %.4lf\n", ynp);
    
    // Corrector
    double ync = adams_bashforth_corrector(y[3], y[2], y[1], y[0], ynp, h);
    
    printf("Corrected y(2) = %.4lf\n", ync);
    
    return 0;
}
