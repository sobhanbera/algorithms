#include <iostream>  
using namespace std;  
int main()  
{  
    int n,rev=0,dig,temp;    
    cout<<"Enter the Number: ";    
    cin>>n;    
    temp=n;    
    while(n!=0)    
    {    
        dig=n%10;    
        rev=(rev*10)+dig;    
        n=n/10;    
    }    
    if(temp==rev)    
        cout<<"Number is Palindrome";    
    else    
        cout<<"Number is not Palindrome";   
    return 0;  
}

/*Outputs:

I: Enter the Number: 252
O: Number is Palindrome

I: Enter the Number: 135
O: Number is not Palindrome
/*
