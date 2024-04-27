#include <stdio.h>
#include <math.h>

double evaluate_polynomial(double x, int degree, double coefficient[])
{
  double result = 0;
  for (int i = 0; i <= degree; i++)
  {
    result += coefficient[i] * pow(x, degree - i);
  }
  return result;
}

double evaluate_derivative(double x, int degree, double coefficient[])
{
  double result = 0;
  for (int i = 0; i <= degree; i++)
  {
    result += (degree - i) * coefficient[i] * pow(x, degree - i - 1);
  }
  return result;
}

double Newton_Raphson(int degree, int coefficient[], double initial_guess, int max_iterations)
{
  double temp = initial_guess;
  int iter = 0;
  while (iter < max_iterations)
  {
    double t = initial_guess - (evaluate_polynomial(temp, degree, coefficient) / evaluate_derivative(temp, degree, coefficient));
    temp=t;

    iter++;
  }
return temp;

}


int main()
{
  int degree;
  int max_iterations;
  printf("Enter the highest degree of the polynomial: ");
  scanf("%d", &degree);
  double coefficient[degree + 1];

  printf("Enter the coefficients of the polynomial starting from highest to lowest degree");
  for (int i = 0; i <= degree; i++)
  {
    printf("Coefficient for x^%d ", degree - i);
    scanf("%lf", &coefficient[i]);
  }

  double initial_guess;
  printf("Enter your initial guess ");
  scanf("%lf", &initial_guess);

  printf("Enter the max no of iterations: ");
  scanf("%d", &max_iterations);

  double root = Newton_Raphson(degree, coefficient, initial_guess, max_iterations);
  printf("Root found at %.6f", root);

  return 0;
}
