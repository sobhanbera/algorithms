#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> v, int n) {
    while (--n > 1) {
        if (v[n] < v[n-1]) {
            return false;
        }
    }
    return true;
}

void shuffle(vector<int> v, int n) {

    for (int i = 0; i < n; i++) {
        swap(v[i], v[rand() % n]);
    }
}
void bogosort(vector<int> v, int n) {

    while(!isSorted(v, n))
        shuffle(v, n);
}

void printarr(vector<int> v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "Enter Size of the Array: ";
    int n;
    cin >> n;
    std::vector<int> v(n);

    cout << "Enter the elements of the Array: " ;
    for (auto &i : v) {
        cin >> i;
    }
    bogosort(v, n);
    cout << "Sorted Array:  " ;
    printarr(v, n);
    return 0;

}

