#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements you want to store in array:"<<endl;
    cin>>n;
    int arr[n];
    int newArr[n];
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
    int j=0,k=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j++;
        }
        else if(arr[i]!=0){
            newArr[k]=arr[i];
            k++;
        }
    }
    for(j;j>=0;j--){
        newArr[k]=0;
        k++;   
    }
    cout<<"New array is:"<<endl;
    for(int i=0;i<n;i++){
        if(i<n-1)
        cout<<newArr[i]<<",";
        else
        cout<<newArr[i];
    }
    return 0;
 }