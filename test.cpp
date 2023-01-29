#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> PreviousSmaller(int arr[], int n)
{ // 6 2 5 4 1 5 6
    vector<int> res;
    stack<int> small;
    small.push(arr[0]);
    res.push_back(-1);
    cout << "-1 ";
    int index;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        index = i;
        while (small.empty() == false && small.top() > arr[i])
        {
            index--;
            count++;
            small.pop();
        }
        int ps = small.empty() ? -1 : index - 1;
        res.push_back(ps);
        cout << ps << " ";
        small.push(arr[i]);
    }
    cout << endl;
    return res;
}
vector<int> NextSmaller(int arr[], int n)
{
    vector<int> res;
    stack<int> smaller;
    // smaller.push(arr[n - 1]);
    // res.push_back(n);
    int index;
    for (int i = n - 1; i >= 0; i--)
    {
        index = i;
        int count = 0;
        while (smaller.empty() == false && smaller.top() > arr[i])
        {
            count++;
            smaller.pop();
        }
        int ns = smaller.empty() ? n : index - 1;
        res.push_back(ns);
        smaller.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return res;
}
int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;
    int curr, res = 0;
    vector<int> prev = PreviousSmaller(arr, n);
    vector<int> next = NextSmaller(arr, n);
    for (int i = 0; i < n; i++)
    {
        curr = arr[i];
        curr += (arr[i] - prev[i] - 1) * arr[i];
        curr += (next[i] - arr[i] - 1) * arr[i];
        res = max(res, curr);
    }
    cout << res;
    return 0;
}