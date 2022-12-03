// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
        int left = 0, sum = 0;
    if(n==1){
        cout<<1;
    }
    else{
        for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    left += arr[0];
    for (int i = 0; i < n; i++)
    {
        if (left == sum - (arr[i] + arr[i + 1]))
        {
            cout << i+2;
            break;
        }
        left += arr[i + 1];
        sum -= arr[i];
    }
    if (left = !sum)
    {
        cout << -1;
    }
    }
    return 0;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends