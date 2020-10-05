#include <iostream>
using namespace std;
void Merge(int* A, int, int, int);
void Merge_Sort(int* A, int p, int r);
int main()
{
    int len, n, i;
    cout << "Array size: ";
    cin >> len;
    int a[len];
    for (i = 0; i < len; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }
    cout << "Initial array: ";
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }

    Merge_Sort(a, 0, len - 1);
    cout << "\nSorted array:  ";
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
void Merge(int* arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
    int i = 0;
    int j = 0;
    int n = 0;
    while (i != n1 && j != n2) {
        if (L[i] > R[j]) {
            arr[p + n] = R[j];
            j++;
        }
        else {
            arr[p + n] = L[i];
            i++;
        }
        n++;
    }
    while (j != n2) {
        arr[p + n] = R[j];
        j++;
        n++;
    }
    while (i != n1) {
        arr[p + n] = L[i];
        i++;
        n++;
    }
}
void Merge_Sort(int* arr, int p, int r)
{
    if (r > p) {
        int q;
        q = (p + r) / 2;
        Merge_Sort(arr, p, q);
        Merge_Sort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}
