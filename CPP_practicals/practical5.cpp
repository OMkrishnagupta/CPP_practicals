#include <iostream>
using namespace std;

int main()
{
    int arr1[50], arr2[50], size1, size2, i, j, k, merge[100];

    cout << "Enter Array 1 Size : ";
    cin >> size1;
    cout << "Enter Array 1 Elements : ";
    for(i=0; i<size1; i++)
        cin >> arr1[i];

    cout << "Enter Array 2 Size : ";
    cin >> size2;
    cout << "Enter Array 2 Elements : ";
    for(i=0; i<size2; i++)
        cin >> arr2[i];

    i=0;
    j=0;
    k=0;

    while(i<size1 && j<size2)
    {
        if(arr1[i] < arr2[j])
        {
            merge[k] = arr1[i];
            i++;
        }
        else
        {
            merge[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i<size1)
    {
        merge[k] = arr1[i];
        i++;
        k++;
    }

    while(j<size2)
    {
        merge[k] = arr2[j];
        j++;
        k++;
    }

    cout << "\nMerged Array : ";
    for(i=0; i<k; i++)
        cout << merge[i] << " ";

    return 0;
}
