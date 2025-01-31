#include <stdio.h>
#include <math.h>

// Define the function using a macro
#define FX(x) ((x) * (x) - 4 * (x) - 10) // Function: f(x) = x^2 - 4x - 10

int main() {
    double x1, x2, x0, f1, f2, f0, E;
    int iterations = 0, max_iterations;
    
    // Input initial values and stopping criteria
    printf("Enter initial guesses x1 and x2: ");
    scanf("%lf %lf", &x1, &x2);
    printf("Enter the tolerance (E): ");
    scanf("%lf", &E);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iterations);
    
    // Compute f(x1) and f(x2)
    f1 = FX(x1);
    f2 = FX(x2);
    
    // Check if initial guesses are valid
    if (f1 * f2 > 0) {
        printf("Invalid initial guesses. The function must have opposite signs at x1 and x2.\n");
        return 1;
    }
    
    printf("\nIter |    x1    |    x2    |    x0    |   f(x0)   \n");
    printf("---------------------------------------------------\n");
    
    do {
        // Compute x0 using False Position formula
        x0 = (x1 * f2 - x2 * f1) / (f2 - f1);
        f0 = FX(x0);
        iterations++;
        
        printf(" %d | %.5lf | %.5lf | %.5lf | %.5lf \n", iterations, x1, x2, x0, f0);
        
        if (f1 * f0 < 0) {
            x2 = x0;
            f2 = f0;
        } else {
            x1 = x0;
            f1 = f0;
        }
        
    } while (fabs(f0) > E && iterations < max_iterations);
    
    printf("---------------------------------------------------\n");
    if (iterations >= max_iterations) {
        printf("Maximum iterations reached. Solution may not be accurate.\n");
    }
    printf("The root is: %lf\n", x0);
    printf("Number of iterations: %d\n", iterations);
    return 0;
}
