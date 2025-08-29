#include <stdio.h>

int fibonacci(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n <= 0)
        return -1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input! Enter a positive integer.\n");
    }
    else
    {
        printf("The value of fibonacci %d is %d\n", n, fibonacci(n));
    }

    return 0;
}
