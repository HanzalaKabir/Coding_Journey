#include<iostream>
using namespace std;

int main(){
    int ele;
    cout<<"Enter the element you want to search in array:"<<endl;
    cin>>ele;
    int  arr[]={34,33,56,56,67,5,6,4,8,577,54,98};
    int n=11;
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            j=i;
            cout<<j<<" ";
        }
    }
    if(j<0){
        cout<<j;
    }
    return 0;
 }