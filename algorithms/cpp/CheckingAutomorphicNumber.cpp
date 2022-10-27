#include <iostream>
using namespace std;
bool isAutomorphic(int N)
{
    int sq = N * N;

    while (N > 0) {
        if (N % 10 != sq % 10)
            return false;

        N /= 10;
        sq /= 10;
    }

    return true;
}
int main()
{
    int n;
    cout << "Enter the Number: "; 
    cin >> n;  
    isAutomorphic(n) ? cout << "Automorphic" : cout << "Not Automorphic";

    return 0;
}



/*
OUTPUTS:

I: Enter the Number: 25
O: Automorphic

I: Enter the Number: 75
O: Not Automorphic
*/
