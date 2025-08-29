#include <stdio.h>
#include <math.h>
void printflwd();
void printflwd()
{
    printf("\n---------------------\n");
    printf("\nWelcome to Simple Calculator:");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modlus");
    printf("\n6. Power");
    printf("\n7. EXIT");
    printf("\n\nChose the number:");
}
int main()
{
    int choice;
    float first, second, result;
    while (1)
    {
        printflwd();
        scanf("%d", &choice);
        if (choice == 7)
        {
            printf("\nEXIT THE SIMPLE CALCULATOR GOOD BUY!!!!");
            printf("\nDEVELOPED BY $CYBERBADFIT$\n\n");
            break;
        }
        if (choice < 1 || choice > 7)
        {
            printf("\nInvalid choice plese select 1 to 7:\n");
            continue;
        }

        printf("\nEnter the first number:");
        scanf("%f", &first);
        printf("\nEnter the second number:");
        scanf("%f", &second);
        switch (choice)
        {
        case 1:
            result = first + second;
            break;
        case 2:
            result = first - second;
            break;

        case 3:
            result = first * second;
            break;

        case 4:
            if (second != 0)
            {
                result = first / second;
            }
            else
            {
                printf("\nError Division by zero is not allowed:");
                continue;
            }

            break;

        case 5:
            result = (int)first % (int)second;
            break;

        case 6:
            result = pow(first, second);
            break;
        default:
            printf("\n Error Invalid oprations:");

            continue;
        }
        printf("\nResult of oprations:%.2f", result);
    }
    return 0;
}