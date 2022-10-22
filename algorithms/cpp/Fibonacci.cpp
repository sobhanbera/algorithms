#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of terms" << endl;
    cin >> n;
    int a = 0, b = 1, sum = 0;

    cout << a << endl
         << b << endl;

    for (int i = 0; i < n - 2; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
        cout << sum << endl;
    }
    return 0;
}