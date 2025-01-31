#include <stdio.h>

#define f(x, y) (1 + 3 * (x) * (x))  // Define the function f(x, y) = 1 + 3x^2

int main() {
    float x0, y0, xp, h, m1, m2, m3, m4, xn, yn;
    int n, i;

    // Get initial values from user
    printf("Enter initial value (x0, y0): ");
    scanf("%f %f", &x0, &y0);
    printf("Enter unknown x (xp): ");
    scanf("%f", &xp);  // Declare and use xp
    printf("Enter step size (h): ");
    scanf("%f", &h);

    // Calculate the number of steps
    n = (int)((xp - x0) / h);

    // Print the table header
    printf("\nStep |    x    |    y    |   m1   |   m2   |   m3   |   m4   |   yn\n");
    printf("-------------------------------------------------------------\n");

    // RK4 method iteration
    for (i = 0; i < n; i++) {
        m1 = f(x0, y0);                     // Calculate m1 = f(x, y)
        m2 = f(x0 + h / 2, y0 + h / 2 * m1);  // Calculate m2 = f(x+h/2, y+h/2*m1)
        m3 = f(x0 + h / 2, y0 + h / 2 * m2);  // Calculate m3 = f(x+h/2, y+h/2*m2)
        m4 = f(x0 + h, y0 + h * m3);         // Calculate m4 = f(x+h, y+h*m3)
        
        yn = y0 + (h / 6) * (m1 + 2 * m2 + 2 * m3 + m4);  // Update y using the RK4 formula
        xn = x0 + h;  // Update x

        printf("%4d | %8.2f | %8.4f | %8.4f | %8.4f | %8.4f | %8.4f | %8.4f\n", 
                i + 1, x0, y0, m1, m2, m3, m4, yn);
        
        x0 = xn;  // Update x0 to xn
        y0 = yn;  // Update y0 to yn
    }

    // Print the final result
    printf("\nValue of y at x = %.3f is %.3f\n", xn, yn);
    return 0;
}
