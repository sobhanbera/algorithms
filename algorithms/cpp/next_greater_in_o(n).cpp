#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    stack <int> s,ind;
    s.push(arr[0]);
    ind.push(0);
    cout<<"Element   Next greater    Index of ele    Index of greater\n";
    for(int i=1;i<n;i++)
    {
        while(!s.empty()&&s.top()<arr[i])
        {
            cout<<s.top()<<"\t\t"<<arr[i]<<"\t\t"<<ind.top()<<"\t\t"<<i<<"\n";
            s.pop();
            ind.pop();
        }
        s.push(arr[i]);
        ind.push(i);
    }
    while(!s.empty())
    {
        cout<<s.top()<<"\t\t"<<-1<<"\t\t"<<ind.top()<<"\n";
        s.pop();
        ind.pop();
    }
    return 0;
}
