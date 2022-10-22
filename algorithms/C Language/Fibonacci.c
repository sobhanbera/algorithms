#include <stdio.h>

int recursive_fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
    {
        return recursive_fib(n - 2) + recursive_fib(n - 1);
    }
}
int main()
{
    int n;
    printf("\nEnter a number : \n");
    scanf("%d", &n);
    printf("\nFibonacci number : %d\n", recursive_fib(n));

    return 0;
}