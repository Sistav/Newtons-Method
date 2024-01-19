#include <stdio.h>

// Init Values
double epsilon;
double value;
double delta;
double squareRoot;
double twoIterAgo;
double oneIterAgo;
double sqrtSquared;
double adjustment;
int absolute;

int main(){

    // Inputs 
    printf ("Value:\n");
    scanf("%lf", &value); 
    printf ("Epsilon:\n");
    scanf("%lf", &epsilon); 


    delta = epsilon + 1;
    squareRoot = 1.0; 
    while (delta > epsilon){
        // Check if we've entered a loop
        if (oneIterAgo == squareRoot || twoIterAgo == squareRoot){
            break;
        }
        // Save the last 2 known values
        twoIterAgo = oneIterAgo;
        oneIterAgo = squareRoot;

        // Get the approximate squared number
        sqrtSquared = squareRoot * squareRoot;

        // Calculate
        adjustment = (sqrtSquared - value) / (2 * squareRoot);
        squareRoot = squareRoot - adjustment;

        // Calculate the difference 
        delta = squareRoot * squareRoot - value;

        // Ensure that delta is positive.
        absolute = delta < 0;
        delta = (-absolute + !absolute) * delta;

        // Print Current Iteration
        printf("%.15lf\n",squareRoot);

    }

    return 1;
}
