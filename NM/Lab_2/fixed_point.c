#include <stdio.h>
#include <math.h>

// Define the function g(x) using a macro (Rearranged form of the original function)
// For the equation f(x) = x^2 - 4x - 10, you can rearrange it as g(x) = (x^2 - 10) / 4
#define GX(x) (((x) * (x) - 10) / 4) // Rearranged form: g(x) = (x^2 - 10) / 4

int main() {
    double x0, x1, E;
    int iterations = 0, max_iterations;
    
    // Input initial value and stopping criteria
    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);
    printf("Enter the tolerance (E): ");
    scanf("%lf", &E);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iterations);
    
    printf("\nIter |    x0    |    x1    |   |x1 - x0|   \n");
    printf("--------------------------------------------\n");
    
    do {
        // Calculate x1 using g(x0)
        x1 = GX(x0);
        iterations++;
        
        printf(" %d | %.5lf | %.5lf | %.5lf \n", iterations, x0, x1, fabs(x1 - x0));
        
        // Check if the absolute difference between x1 and x0 is within the tolerance
        if (fabs(x1 - x0) <= E) {
            break;
        }
        
        x0 = x1;
        
    } while (iterations < max_iterations);
    
    printf("--------------------------------------------\n");
    if (iterations >= max_iterations) {
        printf("Maximum iterations reached. Solution may not be accurate.\n");
    }
    printf("The root is: %lf\n", x1);
    printf("Number of iterations: %d\n", iterations);
    return 0;
}
