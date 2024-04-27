#include <stdio.h>
#include <math.h>

double dy_dx(double x, double y) {
    return 3 * x - 2 * pow(y, 2);
}

double taylor_x_plus_h(double x, double h, double (*f)(double, double)) {
    double derivative = f(x, 1);
    return x + h * derivative;
}

void milne_predictor_corrector(double x0, double y0, double h, double xn, double (*f)(double, double)) {
    double y_pred, y_next;
    double x = x0;
    double y = y0;

    while (x < xn) {
        double x_plus_h = taylor_x_plus_h(x, h, f);
        y_pred = y + (h/24.0) * (55.0 * f(x, y) - 59.0 * f(x-h, y) + 37.0 * f(x-2*h, y) - 9.0 * f(x-3*h, y));
        y_next = y + (h/24.0) * (9.0 * f(x_plus_h, y_pred) + 19.0 * f(x, y) - 5.0 * f(x-h, y) + f(x-2*h, y));

        x += h;
        y = y_next;

        printf("x = %lf, y = %lf\n", x, y);
    }
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h;
    double xn;

    printf("Enter the step size: ");
    scanf("%lf", &h);

    double x1 = x0;
    double x2 = x1 + h;
    double x3 = x2 + h;
    double x4 = x3 + h;

    printf("x1 = %lf\n", x1);
    printf("x2 = %lf\n", x2);
    printf("x3 = %lf\n", x3);
    printf("x4 = %lf\n", x4);

    printf("Enter the final x-value: ");
    scanf("%lf", &xn);

    printf("Milne Predictor-Corrector Method:\n");
    milne_predictor_corrector(x0, y0, h, xn, dy_dx);

    return 0;
}
