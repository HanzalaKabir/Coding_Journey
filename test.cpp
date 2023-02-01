#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
stack<int> _push(int arr[], int n)
{
    stack<int> res;
    int min = arr[0];
    res.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        res.push(arr[i]);
    }
    res.push(min);
    return res;
}
stack<int> _push1(stack<int> res)
{
    stack<int> check = res;
    int min = res.top();
    res.pop();
    while (!res.empty())
    {
        if (res.top() < min)
        {
            min = res.top();
        }
        res.pop();
    }
    check.push(min);
    return check;
}
void _getMinAtPop(stack<int> s)
{
    int min = s.top();
    s.pop();
    while (!s.empty())
    {
        if (min == s.top())
        {
            s.pop();
            cout << min << " ";
            s = _push1(s);
            min = s.top();
            s.pop();
            continue;
        }
        s.pop();
        cout << min << " ";
    }
}
int main()
{
    int n = 6;
    int arr[] = {0, 2, 3, 4, 5, -1};
    stack<int> mys = _push(arr, n);
    _getMinAtPop(mys);
    cout << endl;
    return 0;
}
