#include <stdio.h>

// Function to compute the derivative y'
double derivative(double x, double y) {
    return (x + y) / 2.0;
}

// Milne's Simpson Predictor
double milne_simpson_predictor(double yn_3, double yn_2, double yn_1, double yn, double h) {
    return yn_3 + (4.0 * h / 3.0) * (2 * derivative(0.5, yn_1) - derivative(1.0, yn_2) + 2 * derivative(1.5, yn));
}

// Milne's Simpson Corrector
double milne_simpson_corrector(double yn, double ynp, double h) {
    return derivative(2.0, ynp);
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
    double ynp = milne_simpson_predictor(y[0], y[1], y[2], y[3], h);
    
    printf("Predicted y(2) = %.4lf\n", ynp);
    
    // Corrector
    double ync = milne_simpson_corrector(y[3], ynp, h);
    
    printf("Corrected y(2) = %.4lf\n", ync);
    
    return 0;
}
