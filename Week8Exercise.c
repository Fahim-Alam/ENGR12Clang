#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("I, Fahim Alam, certify that I have completed this assingment in an honest manner.\n");

    // DECLARING VARIABLES
    int orderAgain = 1;   // 1 = true; 0 = false
    int option;           // option 1: cup; option 2: cone
    int orderItemNum = 0; // The number of orders (items) made by the user.
    float cost = 0;       // Cost of the order(s).
    char orderDecision;   // The user's decision whether they would like to order
                          // Another item or not.
    int scoopsNum, i, flavorIndex;
    int totalScoops = 0; // Total # of scoops throughout the order. Set to 0 by default.
    float prices[] = {0.70, 0.75, 0.80, 0.85, 0.90};
    const float SALESTAXRATE = 0.06;
    float salesTax;
    float totalCost; // total cost after the sales tax.
    char splitCheckDecision;
    int people; // # of people if the the people decide to split the check.
    float splitCheck;
    float givenToCharity;

    printf("Welcome to Swanson Scoops!\n");

    printf("What would you like to order? ");
    printf("Enter 1 for a cup and 2 for a cone: ");
    scanf("%d", &option);

    // ERROR ANALYSIS
    while (option != 1 && option != 2)
    {
        printf("Please enter 1 for a cup and 2 for a cone: ");
        scanf("%d", &option);
    }
    switch (option)
    {
    case 1:
        cost += 2.75;
        break;
    case 2:
        cost += 3.25;
        break;
    }
    printf("Total cost: $%.2f\n", cost);

    do
    {
        printf("How many scoops would you like? ");
        scanf("%d", &scoopsNum);

    } while (scoopsNum >= 1 && scoopsNum >= 11);

    printf("Num of scoops: %d\n", scoopsNum);
    totalScoops += scoopsNum;
    printf("Flavor Options:\n\t-Vanilla\t[$0.70]\n\t-Chocolate\t[$0.75]\n\t-Strawberry\t[$0.80]\n\t-Oreo\t\t[$0.85]\n\t-Butter Pecan\t[$0.90]\n");

    for (i = 1; i <= scoopsNum; i++)
    {
        printf("Which flavor would you like for scoop #%d? (Enter V, C, S, O, or B)\n", i);
        char flavorChoice;
        scanf(" %c", &flavorChoice);

        switch (flavorChoice)
        {
        case 'V':
            flavorIndex = 0;
            break;
        case 'C':
            flavorIndex = 1;
            break;
        case 'S':
            flavorIndex = 2;
            break;
        case 'O':
            flavorIndex = 3;
            break;
        case 'B':
            flavorIndex = 4;
            break;
        default:
            printf("Invalid flavor choice.\n");
            i--; // decrement i to repeat the loop for the same # of scoop
            continue;
        }

        cost += prices[flavorIndex];
    }
    orderItemNum += 1;

    printf("Item(s) ordered: #%d\n", orderItemNum);

    // ASKING THE USER IF THEY WOULD LIKE TO ORDER ANOTHER ITEM.
    do
    {
        printf("Would you like to order another item? (Y/N): \n");
        scanf(" %c", &orderDecision);
    } while (orderDecision != 'Y' && orderDecision != 'N');

    while (orderAgain == 1 && orderDecision == 'Y')
    {
        if (orderDecision == 'Y')
        {
            printf("What would you like to order? ");
            printf("Enter 1 for a cup and 2 for a cone: ");
            scanf("%d", &option);

            // ERROR ANALYSIS
            while (option != 1 && option != 2)
            {
                printf("Please enter 1 for a cup and 2 for a cone: ");
                scanf("%d", &option);
            }
            switch (option)
            {
            case 1:
                cost += 2.75;
                break;
            case 2:
                cost += 3.25;
                break;
            }
            printf("Total cost: $%.2f\n", cost);

            do
            {
                printf("How many scoops would you like? ");
                scanf("%d", &scoopsNum);
            } while (scoopsNum >= 1 && scoopsNum >= 11);

            printf("Num of scoops: %d\n", scoopsNum);
            printf("Flavor Options:\n\t-Vanilla\t[$0.70]\n\t-Chocolate\t[$0.75]\n\t-Strawberry\t[$0.80]\n\t-Oreo\t\t[$0.85]\n\t-Butter Pecan\t[$0.90]\n");

            for (i = 1; i <= scoopsNum; i++)
            {
                printf("Which flavor would you like for scoop #%d? (Enter V, C, S, O, or B)\n", i);
                char flavorChoice;
                scanf(" %c", &flavorChoice);

                switch (flavorChoice)
                {
                case 'V':
                    flavorIndex = 0;
                    break;
                case 'C':
                    flavorIndex = 1;
                    break;
                case 'S':
                    flavorIndex = 2;
                    break;
                case 'O':
                    flavorIndex = 3;
                    break;
                case 'B':
                    flavorIndex = 4;
                    break;
                default:
                    printf("Invalid flavor choice, please try again.\n");
                    i--; // decrement i to repeat the loop for the same # of scoop
                    continue;
                }

                cost += prices[flavorIndex];
            }
            orderItemNum += 1;
            totalScoops += scoopsNum;

            printf("Item(s) ordered: #%d\n", orderItemNum);

            // ASKING THE USER IF THEY WOULD LIKE TO ORDER ANOTHER ITEM.
            do
            {
                printf("Would you like to order another item? (Y/N): \n");
                scanf(" %c", &orderDecision);
            } while (orderDecision != 'Y' && orderDecision != 'N');
        }
        else if (orderDecision == 'N')
        {
            salesTax = cost * SALESTAXRATE;
            totalCost = cost + salesTax;
            printf("Your total cost: $%.2f", totalCost);
            printf("Total number of scoops: %d.\n", totalScoops);
            givenToCharity = (totalCost / 3.0) + (totalScoops / 4.0);
            printf("Amount given to charity: $%.2f\n.", givenToCharity);
            orderAgain = 0;
        }
    }

    salesTax = cost * SALESTAXRATE;
    totalCost = cost + salesTax;
    printf("Your total cost: $%.2f\n", totalCost);
    printf("Total number of scoops: %d.\n", totalScoops);
    givenToCharity = (float)(totalCost / 3) + (totalScoops / 4);
    printf("Amount given to charity: $%.2f.\n", givenToCharity);

    // OPTION FOR THE USER TO SPLIT THE CHECK
    printf("Do you need to split the check? (Y/N): ");
    scanf("%s", &splitCheckDecision);

    if (splitCheckDecision == 'Y')
    {
        printf("\nHow many ways do you need to split the check? ");
        scanf("%d.", &people);
        splitCheck = totalCost / people;
        printf("\nThe cost per person: $%.2f.\n", splitCheck);
    }
    else if (splitCheckDecision == 'N')
    {
        printf("\nYour total cost: $%.2f\n", totalCost);
    }
    return 0;
}