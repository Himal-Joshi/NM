#include <stdio.h>
#include <math.h>

// Define the function to integrate
#define f(x) (1 + x * x)  // Example: f(x) = 1 + x^2

int main() {
    float a, b, h, sum, integral;
    int n, i;

    // Read input values
    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    printf("Enter number of subintervals (n): ");
    scanf("%d", &n);

    // Compute step size
    h = (b - a) / n;

    // Compute integral using Trapezoidal Rule
    sum = f(a) + f(b);
    for (i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }
    integral = (h / 2) * sum;

    // Print the result
    printf("The approximate integral using Composite Trapezoidal Rule is: %.6f\n", integral);
    return 0;
}
