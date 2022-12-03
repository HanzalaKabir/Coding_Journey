#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0, right = 0;
    int a , b ;
    if (n == 1)
    {
        cout <<n;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            a = accumulate(arr, arr + i, left);
            b = accumulate(arr + i + 1, arr + n, right);
            if (a == b)
            {
                cout<< i+1<< endl;
                break;
            }
        }
        if(a!=b){
            cout<<"-1";
        }
    }
    return 0;
}