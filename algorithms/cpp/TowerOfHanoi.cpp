#include <iostream>
using namespace std;

void move(int n, char tower_one, char tower_two, char tower_three)
{
    if (n == 1)
    {
        cout << "Transfer from Tower " << tower_one << " to Tower " << tower_three << endl;
    }
    else
    {
        move(n - 1, tower_one, tower_three, tower_two);
        cout << "Transfer from Tower " << tower_one << " to Tower " << tower_three << endl;
        move(n - 1, tower_two, tower_one, tower_three);
    }
}

int main()
{
    int n;
    cout << "Enter the number of Discs :" << endl;
    cin >> n;

    move(n, 'A', 'B', 'C'); // Move n discs from Tower A to C using B
    return 0;
}