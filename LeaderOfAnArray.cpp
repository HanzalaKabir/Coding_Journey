#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in array:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The leaders of the given array are:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] > arr[i])
    //         {
    //             break;
    //         }
    //         if (j == n - 1 && arr[i] >= arr[j])
    //         {
    //             cout << arr[i] << " ";
    //         }
    //     }
    // }
    // cout << arr[n - 1];
    int curr_leader=arr[n-1];
    cout<<curr_leader<<" ";
    for(int i=n-2;i>=0;i--){
        if(arr[i]>=curr_leader)
        {
            curr_leader=arr[i];
            cout<<curr_leader<<" ";
        }
    }
    return 0;
}