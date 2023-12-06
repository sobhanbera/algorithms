#include <iostream>
int main()
{
    int n;
    std::cout << "Enter the number of terms" << std::endl;
    std::cin >> n;
    int a = 0, b = 1, sum = 0;
    if (n > 0)
    {
        std::cout << a << " " << b << " ";
        for (int i = 0; i < n - 2; i++)
        {
            sum = a + b;
            a = b;
            b = sum;
            std::cout << sum << " ";
        }
        std::cout << endl;
    }
    else
    {
        std::cout << "Number should be greater than 0" << std::endl;
    }
    return 0;
}

/* Output:

Enter the number of terms
INPUT- 4
OUTPUT- 0 1 1 2
*/
