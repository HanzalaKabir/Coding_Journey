#include <iostream>
using namespace std;

int main()
{
    // int n;
    // int d;
    // cout << "Enter the number of elements you want to store in array:" << endl;
    // cin >> n;
    // cout << "Enter the number by which you want to rotate the array:" << endl;
    // cin >> d;
    // int arr[n];
    // int temp[d];
    // cout << "Enter the elements of the array:" << endl;
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    int d=2;
    int temp;
    
    for(int j=0;j<d;j++){
        for(int i=0;i<n-1;i++){
            temp=arr[0];
            arr[i]=arr[i+1];
        }
    }
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}