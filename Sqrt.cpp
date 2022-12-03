#include <iostream>
using namespace std;
int BinarySearch(int x)
{
    int low = 0, high = x, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            low = mid + 1;
            ans = mid;
        }
        else if (mid * mid > x)
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int x;
    cin >> x;
    cout << BinarySearch(x);
    return 0;
}