#include <bits/stdc++.h>

using namespace std;
#define ll long long

// https://leetcode.com/problems/pascals-triangle/
// https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1

// Pascal's Triangle
// Given a positive integer N,
// return the Nth row of pascal's triangle.

// Input Format
// First Line contains number of test cases T
// Next T Lines contains integer N representing Nth Row

// Output Format
// T Lines containing Nth Row of Pascal's Triangle 

class Solution{
     const int mod = 1e9+7;
public:

    // 1st method

    // vector<ll> nthRowOfPascalTriangle(int n) {
    //     vector<vector<ll>> v(n);
    //     v[0].push_back(1);
    //     for(int i=1;i<n;i++)
    //     {
    //         for(int j=0;j<=i;j++)
    //         {
    //             if(j==0 || j==i)
    //             {
    //                 v[i].push_back(1);
    //             }
    //             else{
    //                 v[i].push_back((v[i-1][j]+v[i-1][j-1])%mod);
    //             }
    //         }
    //     }
    //     return v[n-1];
    // }

    // 2nd Method

    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll> res;
        res.push_back(1);
        vector<ll> temp;
        
        for(int i=1;i<n;i++){
            temp.push_back(1);
            for(int j=1;j<i;j++){
                temp.push_back((res[j-1]+res[j])%mod);
            }
            temp.push_back(1);
            
            res = temp;
            temp.clear();
        }
        return res;
    }

};


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
