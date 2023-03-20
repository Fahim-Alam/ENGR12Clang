#include <stdio.h>

int main()
{

    // PRINTING PARAGRAPHS
    printf("The first \\n puts the text on a new line, the double slash by the n is needed to allow the printing of the \\n on this printout.\n\n");
    printf("Sometimes it is nice to print out text in \"double quotes\", this requires the double quote escape sequence \\ . Sometimes it is nice to print of text in \' 'single quotes'\', this requires the single quote escape sequence \\'.");
    printf("\n\nWwant to print out a %%? You need to use the escape sequence \"%%\", do you\nunderstand\nthe code required to print this sequence out?\n");

    // CREATING AND PRINTING VARIABLES
    int A;
    double B;
    char C;

    printf("Enter an integer value: ");
    scanf("%d", &A);
    printf("Enter a double value: ");
    scanf("%lf", &B);
    printf("Enter a single-value character: ");
    scanf(" %c", &C);

    printf("\n%d\n", A);
    printf("%f\n", B);
    printf("%c\n", C);

    // WOKRING WITH ARRAYS
    int G[] = {3, 5, 8, 9};

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", G[i]);
    }

    float H[2][2] = {{4.4, 5.5}, {6.6, 7.7}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.1lf\n", H[i][j]);
        }
    }

    return 0;
}
