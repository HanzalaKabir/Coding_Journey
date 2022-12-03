#include <iostream>
using namespace std;
int BinarySearch(int arr[], int x, int n, int low, int high, int pos)
{
    if (low > high)
    {
        return pos;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            pos = mid;
            return pos - 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
            return BinarySearch(arr, x, n, low, high, pos);
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
            return BinarySearch(arr, x, n, low, high, pos);
        }
    }
    return -1;
}
int main()
{
    int pos = -1;
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int low = 0, high = n - 1;
    int ans = BinarySearch(arr, x, n, low, high, pos);
    return ans;
    return 0;
}