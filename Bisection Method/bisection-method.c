#include <stdio.h>
#include <math.h>
double function(double x) {
    return (x*x*x)-x - 1;
}
double bisection(double a, double b, double tolerance) {
    double c;
    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        if (function(c) == 0.0) {
            break;
        }
        if (function(c) * function(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}


int main() {
    double a, b, accuracy, root;

    printf("\n\nEnter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter Accuracy: ");
    scanf("%lf", &accuracy);
    if (function(a) * function(b) >= 0) {
        printf("Invalid initial values. They should have opposite signs.\n");
        return 1;
    }

    root = bisection(a, b, accuracy);
    printf("Root is approximately: %lf\n", root);

    return 0;
}
