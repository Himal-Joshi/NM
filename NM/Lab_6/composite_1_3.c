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
    printf("Enter number of subintervals (n - must be even): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error: n must be even for Simpson's 1/3 Rule.\n");
        return 1;
    }

    // Compute step size
    h = (b - a) / n;

    // Compute integral using Simpson's 1/3 Rule
    sum = f(a) + f(b);
    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 4 * f(a + i * h);
        }
    }
    integral = (h / 3) * sum;

    // Print the result
    printf("The approximate integral using Composite Simpson's 1/3 Rule is: %.6f\n", integral);
    return 0;
}
