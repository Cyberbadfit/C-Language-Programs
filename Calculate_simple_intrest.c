#include <stdio.h>
int main()
{
    // variables
    int principleAmount, numberOfYears, rateOfInterest, SimpleInterest;
    // user input function
    printf("enter principleAmount\n", principleAmount);
    scanf("%d", &principleAmount);
    printf("enter number of year\n", numberOfYears);
    scanf("%d", &numberOfYears);
    printf("enter rate of interest\n", rateOfInterest);
    scanf("%d", &rateOfInterest);

    // basic calculation to find the simple intrest
    SimpleInterest = (principleAmount * numberOfYears * rateOfInterest) / 100;
    // output
    printf("Simple interest is %d", SimpleInterest);

    return 0;
}