#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(int arr[], int n)
{
    set<int> s(arr, arr + n);
    int j = 0;
    for (auto i : s)
        arr[j++] = i;
    while (j < n)
        arr[j++] = 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    removeDuplicates(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
