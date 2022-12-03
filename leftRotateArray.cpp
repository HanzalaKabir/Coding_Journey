#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements you want to store in array:"<<endl;
    cin>>n;
    int arr[n];
    //int j=1;
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Given array is:"<<endl;
    for(int i=0;i<n;i++){
        if(i<n-1)
        cout<<arr[i]<<",";
        else
        cout<<arr[i]<<endl;
    }
    // for(int i=0;i<n-1;i++){
    //     swap(arr[i],arr[j]);
    //     j++;
    // }
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
        arr[n-1]=temp;
    cout<<"Reverted array is:"<<endl;
    for(int i=0;i<n;i++){
        if(i<n-1)
        cout<<arr[i]<<",";
        else
        cout<<arr[i]<<endl;
    }    return 0;
 } 