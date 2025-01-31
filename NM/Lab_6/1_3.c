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
    h = (b - a) / 2;

    // Compute integral using Simple Simpson’s 1/3 Rule
    integral = (h / 3) * (f(a) + 4 * f((a + b) / 2) + f(b));

    // Print the result
    printf("The approximate integral using Simple Simpson's 1/3 Rule is: %.6f\n", integral);
    return 0;
}
