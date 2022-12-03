#include <stdio.h>
#include <iostream>
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
    int large = arr[0];
    int index;
    for (int i = 1; i < n; i++)
    {
        if (large < arr[i])
        {
            large = arr[i];
            index = i;
        }
    }
    cout << "Largest element in the array is:" << large << endl
         << "Element number of the largest elements is:" << index + 1;
}