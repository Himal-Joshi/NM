#include <stdio.h>
#include <math.h>

// Define the function using a macro
#define FX(x) ((x) * (x) - 4 * (x) - 10) // Function: f(x) = x^2 - 4x - 10

// Define the derivative of the function using a macro
#define FX_DERIV(x) (2 * (x) - 4) // Derivative: f'(x) = 2x - 4

int main() {
    double x0, x1, f0, f_prime, E;
    int iterations = 0, max_iterations;
    
    // Input initial value and stopping criteria
    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);
    printf("Enter the tolerance (E): ");
    scanf("%lf", &E);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iterations);
    
    printf("\nIter |    x0    |    x1    |   f(x1)   \n");
    printf("----------------------------------------\n");
    
    do {
        f0 = FX(x0);
        f_prime = FX_DERIV(x0);
        
        // Compute x1 using Newton-Raphson formula
        if (f_prime == 0) {
            printf("Derivative is zero. Cannot proceed with the method.\n");
            break;
        }
        x1 = x0 - f0 / f_prime;
        iterations++;
        
        printf(" %d | %.5lf | %.5lf | %.5lf \n", iterations, x0, x1, FX(x1));
        
        // Check if the relative error is within the tolerance
        if (fabs(x1 - x0) < E) {
            break;
        }
        
        x0 = x1;
        
    } while (iterations < max_iterations);
    
    printf("----------------------------------------\n");
    if (iterations >= max_iterations) {
        printf("Maximum iterations reached. Solution may not be accurate.\n");
    }
    printf("The root is: %lf\n", x1);
    printf("Number of iterations: %d\n", iterations);
    return 0;
}
