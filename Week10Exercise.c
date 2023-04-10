#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void introFunc() // Function 1
{
    printf("Date: 04.7.2023\n");
    printf("Team 4: Name: Fahim Alam\n");
    printf("\nThe purpose of this program is to do some math and matrix operations\n");
}

int userChoice(int option) // Function 2
{
    printf("\nWould you like to perform math operations or create an array?\n1)Math operations\n2)Array\n");
    printf("Enter integer value for choice (1 or 2): ");
    scanf(" %d", &option);
    while ((option != 1) && (option != 2))
    {

        printf("\nERROR: You must enter a 1 or 2?\nTry again: ");
        scanf(" %d", &option);
    }
    return option;
}

double mathOpp(char operation, int option, double val1, double val2) // Function 3
{
    double result;
    printf("\nEnter a value for the first number: ");
    scanf("%lf", &val1);
    printf("\nEnter a value for the second number: ");
    scanf("%lf", &val2);

    printf("\nSelect the math operation to perform on the two numbers.\na - Addition\ns - Subtraction\nm - Multiplication\nd - Division\n");
    printf("\nEnter char value for choice (a, s, n, or, d): ");
    scanf(" %c", &operation);

    while ((operation != 'a') && (operation != 's') && (operation != 'm') && (operation != 'd'))
    {
        printf("\nERROR: You must enter a, s, m, or, d!\nTry again: ");
        scanf(" %c", &operation);
    }
    switch (operation)
    {
    case 'a':
        result = val1 + val2;
        break;
    case 's':
        result = val1 - val2;
        break;
    case 'm':
        result = val1 * val2;
        break;
    case 'd':
        result = val1 / val2;
        break;
    }
    return result;
}

void displayResults() // Function 4
{
    char operation;
    int option;
    double val1, val2, result;
    FILE *outfpt = fopen("hw10_results.txt", "r");
    outfpt = fopen("hw10_results.txt", "a");
    printf("The two values you entered were %f and %f\n", val1, val2);
    printf("Of the math operations a-add, s-subtract, m-multiply, d-divide, you chose: \n%c\n", operation);
    printf("The calculated result is %.2f\n", result);

    fprintf(outfpt, "The two values you entered were %f and %f\n", val1, val2);
    fprintf(outfpt, "Of the math operations a-add, s-subtract, m-multiply, d-divide, you chose: \n%c\n", operation);
    fprintf(outfpt, "The calculated result is %.2f\n", result);
}

void createMatrix(int arr[], int matrix_len, int *max_val, int *max_idx)
{
    printf("How many elements would you like?\n");
    scanf("%d", &matrix_len);
    while (matrix_len >= 1 && matrix_len >= 6)
    {
        printf("Error! Enter a number between 1 and 5\n");
        scanf("%d", &matrix_len);
    }
    // Input elements of the array
    for (int i = 0; i < matrix_len; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
        if (i == 0 || arr[i] > *max_val)
        {
            *max_val = arr[i];
            *max_idx = i;
        }
    }
}

void displayMatrix(int matrix[], int matrix_len, int max_val, int max_idx)
{
    FILE *outfpt = fopen("hw10_results.txt", "r");
    outfpt = fopen("hw10_results.txt", "a");

    printf("The array you entered is:\n");
    fprintf(outfpt, "The array you entered is:\n");
    for (int i = 0; i < matrix_len; i++)
    {
        printf("%d ", matrix[i]);
        fscanf(outfpt, "%d ", &matrix[i]);
        fprintf(outfpt, "% d ", matrix[i]);
    }
    printf("\n");
    fprintf(outfpt, "\n");

    // Display maximum value and its location
    printf("The maximum number is %d at location %d\n", max_val, max_idx);
    fprintf(outfpt, "The maximum number is %d at location %d\n", max_val, max_idx);
}

int main()
{
    int matrix_len, max_val, max_idx;
    int matrix[matrix_len];
    max_val = 0;
    double num1, num2, result;
    char operation, goAgain = 'y';
    FILE *outfpt = fopen("hw10_results.txt", "r");
    outfpt = fopen("hw10_results.txt", "a");

    printf("I, Fahim Alam, certify that I have completed this assignment in an honest manner.\n");
    introFunc();
    int option = userChoice(option);
    if (option == 1)
    {
        mathOpp(operation, option, num1, num2);
        displayResults();
    }
    else
    {
        createMatrix(matrix, matrix_len, &max_val, &max_idx);
        printf("Enter number of elements: ");
        scanf("%d", &matrix_len);
        displayMatrix(matrix, matrix_len, max_val, max_idx);
    }
    printf("\nWould you like to run this program again (y/n)? ");
    scanf(" %c", &goAgain);

    while (!(goAgain == 'y') && !(goAgain == 'n'))
        ;
    {
        printf("Error, please enter Y or N (y/n): ");
        scanf(" %c", &goAgain);
    }

    while (goAgain)
    {
        if (goAgain == 'y')
        {
            int option = userChoice(option);
            if (option == 1)
            {
                mathOpp(operation, option, num1, num2);
                displayResults();
            }
            else
            {
                createMatrix(matrix, matrix_len, &max_val, &max_idx);
                printf("Enter number of elements: ");
                scanf("%d", &matrix_len);
                displayMatrix(matrix, matrix_len, max_val, max_idx);
            }
            printf("Would you like to run this program again (y/n)? ");
            scanf(" %c", &goAgain);

            do
            {
                printf("Error, please enter Y or N (y/n): ");
                scanf(" %c", &goAgain);
            } while (!(goAgain == 'y') && !(goAgain == 'n'));
        }
        else
        {
            goAgain = 'y';
            break;
        }
        break;
    }
    return 0;
}