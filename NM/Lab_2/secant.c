#include <stdio.h>
#include <math.h>

// Define the function using a macro
#define FX(x) ((x) * (x) - 4 * (x) - 10) // Function: f(x) = x^2 - 4x - 10

int main() {
    double x0, x1, x2, f0, f1, E;
    int iterations = 0, max_iterations;
    
    // Input initial values and stopping criteria
    printf("Enter initial guesses x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter the tolerance (E): ");
    scanf("%lf", &E);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iterations);
    
    printf("\nIter |    x0    |    x1    |    x2    |   f(x2)   \n");
    printf("---------------------------------------------------\n");
    
    do {
        f0 = FX(x0);
        f1 = FX(x1);
        
        // Compute x2 using Secant Method formula
        x2 = x1 - ((x1 - x0) / (f1 - f0)) * f1;
        iterations++;
        
        printf(" %d | %.5lf | %.5lf | %.5lf | %.5lf \n", iterations, x0, x1, x2, FX(x2));
        
        if (fabs(x2 - x1) < E) {
            break;
        }
        
        x0 = x1;
        x1 = x2;
        
    } while (iterations < max_iterations);
    
    printf("---------------------------------------------------\n");
    if (iterations >= max_iterations) {
        printf("Maximum iterations reached. Solution may not be accurate.\n");
    }
    printf("The root is: %lf\n", x2);
    printf("Number of iterations: %d\n", iterations);
    return 0;
}
