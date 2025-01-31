#include <stdio.h>
#include <math.h>

// Define the function to integrate
#define f(x) (1 + x * x)  // Example function: f(x) = 1 + x^2

int main() {
    float a, b, h, sum, integral;
    int n, i;

    // Read input values
    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    printf("Enter number of subintervals (n - must be a multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0) {
        printf("Error: n must be a multiple of 3 for Simpson's 3/8 Rule.\n");
        return 1;
    }

    // Compute step size
    h = (b - a) / n;

    // Compute integral using Simpson's 3/8 Rule
    sum = f(a) + f(b);
    for (i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 3 * f(a + i * h);
        }
    }
    integral = (3 * h / 8) * sum;

    // Print the result
    printf("The approximate integral using Composite Simpson's 3/8 Rule is: %.6f\n", integral);
    return 0;
}
