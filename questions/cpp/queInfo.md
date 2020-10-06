//Add any competitive programming question with solution in this folder you want in C++ language. for more info read the readme in the main repository directory.
//Please add some comments to understand what your code is doing.
//Thanks...
Question : Program to Add Two Integers

Solution :

#include <iostream>
using namespace std;

int main()
{
    int firstNumber, secondNumber, sumOfTwoNumbers;
    
    cout << "Enter two integers: ";
    cin >> firstNumber >> secondNumber;

    // sum of two numbers in stored in variable sumOfTwoNumbers
    sumOfTwoNumbers = firstNumber + secondNumber;

    // Prints sum 
    cout << firstNumber << " + " <<  secondNumber << " = " << sumOfTwoNumbers;     

    return 0;
}
