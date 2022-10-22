#include <stdio.h>

int fact_Loop(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    int n;

    printf("\nEnter a number: \n");
    scanf("%d", &n);

    int fact = fact_Loop(n);
    printf("\nFactorial is : %d\n", fact);

    return 0;
}