#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements you want to store in array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int large = arr[0];
    int seclarge = -1;
    for (int i = 1; i < n; i++)
    {
        if (large > arr[i])
        {
            if (arr[i] > seclarge)
            {
                seclarge = arr[i];
            }
        }
        else if (arr[i] > large)
        {
            seclarge = large;
            large = arr[i];
        }
        else if (arr[i] < large)
        {
            if (arr[i] > seclarge)
            {
                seclarge = arr[i];
            }
        }
    }
    cout << large << " " << seclarge;
    return 0;
}