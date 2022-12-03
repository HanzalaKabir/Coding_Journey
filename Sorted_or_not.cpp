#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements you want to store in array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = n-1;
    int j = 0;
    while (i > 0)
    {
        if (arr[j + 1] > arr[j])
        { 
            i--;
            j++;
        }
        else
        {
            cout << "not sorted" << endl;
            break;
        }
    }
    if (j == n - 1)
    {
        cout << "sorted";
    }
    return 0;
}