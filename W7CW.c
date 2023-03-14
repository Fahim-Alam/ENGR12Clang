#include <stdio.h>
#include <stdlib.h>

int main()
{

    double x, y, u, v;

    char letter = 'A';
    x = 5;
    printf("I like C\n");
    y = 2 * x;

    printf("x: %.1f\n", x);
    printf("y: %.1f\n", y);

    printf("Enter a value for the variable for u: ");
    scanf("%lf", &u);

    printf("Enter a value for the variable for v: ");
    scanf("%lf", &v);

    printf("x: %.1f\n", u);
    printf("y: %.1f\n", v);

    int favNumber;
    printf("What you favorite number: ");
    scanf("%d", &favNumber);
    printf("Your favorite number is: %d\n", favNumber);

    return 0;
}