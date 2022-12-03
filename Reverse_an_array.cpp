#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements you want to store in array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"The given array is:"<<endl;
    for(int i=0;i<n;i++){
        if(i<n-1)
        cout<<arr[i]<<",";
        else
        cout<<arr[i]<<endl;
    }
    int i=n-1;
    int j=0;
    while(i>=(n/2)+1){
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        i--;
        j++;
    }
    cout<<"The new arrays is:"<<endl;
    for(int i=0;i<n;i++){
        if(i<n-1)
        cout<<arr[i]<<",";
        else
        cout<<arr[i];
    }
    return 0;
 }