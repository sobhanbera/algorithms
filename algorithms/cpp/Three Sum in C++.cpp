#include<iostream>
using namespace std;

// declaring function
double add(double n1, double n2, double n3);

// main function
int main()
{
  // declaring variables
  double n1, n2, n3;
  double sum;

  // taking input from the user
  cout << "Enter three Numbers :: ";
  cin >> n1 >> n2 >> n3;

  // calculating sum value
  sum = add(n1 , n2, n3);

  // displaying result
  cout << "Sum = " << sum << endl;

  return 0;
}

// function to add three numbers
double add(double n1, double n2, double n3)
{
    return n1+n2+n3;
}
