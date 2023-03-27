#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main()
{
    printf("I, Fahim Alam, certify that I have completed this assignment in an honest manner.\n");
    char filename[100];
    FILE *filePointer = NULL;
    FILE *resultsPointer = fopen("results.txt", "w");
    while (filePointer == NULL)
    {
        printf("Enter a file name: ");
        if (scanf("%s", filename) == 1)
        {
            filePointer = fopen(filename, "r");
            if (filePointer == NULL)
            {
                printf("Error opening file '%s'. Please try again.\n", filename);
            }
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }
    printf("File '%s' opened successfully.\n", filename);

    // fclose(filePointer);

    int matrix[500][2];
    int i = 0;
    int j = 0;
    int check;
    int col_sum[2] = {0, 0};

    for (int i = 1; i <= sizeof(matrix) / sizeof(matrix[0]); i++)
    {
        {
            check = fscanf(filePointer, "%d %d", &matrix[i][0], &matrix[i][1]);
            if (check == EOF)
            {
                break;
            }
            printf("Temperatures on Day %i in 1930 = %d\t2001 = %d\t", i, matrix[i][0], matrix[i][1]);
        }
        fprintf(resultsPointer, "Temperatures on Day %i in 1930 = %d\t2001 = %d\n", i, matrix[i][0], matrix[i][1]);

        printf("\n");
    }
    fprintf(resultsPointer, "*************************************************\n");
    // FINDING THE MEAN AND STANDARD DEVIATION
    int sum_col1 = 0, sum_col2 = 0;
    double mean_col1, mean_col2, sd_col1 = 0.0, sd_col2 = 0.0;
    for (i = 1; i <= 365; i++)
    {
        sum_col1 += matrix[i][0];
        sum_col2 += matrix[i][1];
    }

    mean_col1 = sum_col1 / 365;
    mean_col2 = sum_col2 / 365;

    for (i = 0; i < 365; i++)
    {
        sd_col1 += pow(matrix[i][0] - mean_col1, 2);
        sd_col2 += pow(matrix[i][1] - mean_col2, 2);
    }

    sd_col1 = sqrt(sd_col1 / 365);
    sd_col2 = sqrt(sd_col2 / 365);

    // FIND THE MIN AND MAX
    float min1 = FLT_MAX, max1 = matrix[0][0], min2 = FLT_MAX, max2 = matrix[0][1];
    for (int k = 0; k < 365; k++)
    {
        if (matrix[k][0] < min1)
        {
            min1 = matrix[k][0];
        }
        if (matrix[k][0] > max1)
        {
            max1 = matrix[k][0];
        }
    }

    // Find the minimum and maximum values for column 2
    for (int k = 0; k < 365; k++)
    {
        if (matrix[k][1] < min2)
        {
            min2 = matrix[k][1];
        }
        if (matrix[k][1] > max2)
        {
            max2 = matrix[k][1];
        }
    }

    int min_diff = abs(matrix[0][0] - matrix[0][1]);
    for (int i = 1; i < 3; i++)
    {
        int diff = abs(matrix[i][0] - matrix[i][1]);
        if (diff < min_diff)
        {
            min_diff = diff;
        }
    }

    int max_diff = abs(matrix[0][0] - matrix[0][1]);

    for (int i = 1; i < 3; i++)
    {
        int diff = abs(matrix[i][0] - matrix[i][1]);
        if (diff > max_diff)
        {
            max_diff = diff;
        }
    }

    // OUTPUTING THE RESULTS.
    fprintf(resultsPointer, "I, Fahim Alam, certify that I have completed this assignment in an honest manner.\n");
    printf("\nThe average temp for 1930 is: %.2f\n", mean_col1);
    printf("The average temp for 2001 is: %.2f \n", mean_col2);
    fprintf(resultsPointer, "\nThe average temp for 1930 is: %.2f\n", mean_col1);
    fprintf(resultsPointer, "The average temp for 2001 is: %.2f \n", mean_col2);
    printf("The min temp for 1930 is: %.2f\n", min1);
    printf("The min temp for 2001 is: %.2f\n", min2);
    printf("The max temp for 1930 is: %.2f\n", max1);
    printf("The max temp for 2001 is: %.2f\n", max2);
    fprintf(resultsPointer, "The min temp for 1930 is: %.2f\n", min1);
    fprintf(resultsPointer, "The min temp for 2001 is: %.2f\n", min2);
    fprintf(resultsPointer, "The max temp for 1930 is: %.2f\n", max1);
    fprintf(resultsPointer, "The max temp for 2001 is: %.2f\n", max2);
    printf("The min difference between 1930 and 2001 is: %d\n", min_diff);
    fprintf(resultsPointer, "The min difference between 1930 and 2001 is: %d\n", min_diff);
    printf("The max difference between 1930 and 2001 is: %d\n", max_diff);
    fprintf(resultsPointer, "The max difference between 1930 and 2001 is: %d\n", max_diff);
    printf("The standard deviation for 1930 is: %.2f\n", sd_col1);
    printf("The standard deviation for 2001 is: %.2f\n", sd_col2);
    fprintf(resultsPointer, "The standard deviation for 1930 is: %.2f\n", sd_col1);
    fprintf(resultsPointer, "The standard deviation for 2001 is: %.2f\n", sd_col2);

    return 0;
}
