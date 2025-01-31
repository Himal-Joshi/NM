#include <stdio.h>
#include <math.h>

// Define the function to integrate
#define f(x) (1 + x * x)  // Example: f(x) = 1 + x^2

int main() {
    float a, b, h, integral;

    // Read input values
    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    // Compute step size
    h = b - a;

    // Compute integral using the Simple Trapezoidal Rule
    integral = (h / 2) * (f(a) + f(b));

    // Print the result
    printf("The approximate integral using Simple Trapezoidal Rule is: %.6f\n", integral);
    return 0;
}
