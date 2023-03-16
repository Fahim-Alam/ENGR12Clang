#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int apples = 5;
    int bananas;
    double oranges;
    double grapes;
    char firstLetter;

    printf("Please provide the values for bananas: ");
    scanf("%d", &bananas);

    printf("\nPlease provide the values for oranges: ");
    scanf("%lf", &oranges);

    printf("\nPlease provide the values for grapes: ");
    scanf("%lf", &grapes);

    printf("Apples: %d\t Bananas: %d\n", apples, bananas);
    printf("Oranges: %.2f\t Grapes: %.2f\n", oranges, grapes);

    printf("Please provide the first letter of your first name: ");
    scanf(" \n%c", &firstLetter);

    printf("\nFirst letter = %c\n", firstLetter);

    int array[5] = {2,
                    1,
                    3,
                    5,
                    7};
    int array2[2][4] = {{2, 4, 6, 8},
                        {1, 3, 5, 7}};

    // PRINTING 1ST AND LAST ELEMENTS FROM ARRAY var
    int firstElement = array[0];
    int lastElement = array[sizeof(array) - 1];
    printf("%d\n", firstElement);
    printf("%d\n", lastElement);

    // PRINTING 1ST AND LAST ELEMENTS FROM ARRAY2 var
    int firstElement2 = array2[0][0];
    int lastElement2 = array2[0][3];
    printf("%d\n", firstElement2);
    printf("%d\n", lastElement2);

    char message[20] = "Programming in C";
    printf("%s\n", message);
    return 0;
}