#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int size)
    {
        stack<int> temp;
        int middle = ceil((size + 1) / 2);
        int i = 1, ele;
        if (size % 2 == 0)
        {
            while (i <= middle)
            {
                ele = s.top();
                s.pop();
                temp.push(ele);
                i++;
            }
        }
        else
        {
            while (i < middle)
            {
                ele = s.top();
                s.pop();
                temp.push(ele);
                i++;
            }
        }
        s.pop();
        while (i >= 1)
        {
            if (temp.empty() == true)
            {
                break;
            }
            ele = temp.top();
            temp.pop();
            s.push(ele);
            i--;
        }
    }
};
int main()
{
    int size;
    cin >> size;
    stack<int> MyStack;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        MyStack.push(x);
    }
    Solution object;
    object.deleteMid(MyStack, MyStack.size());
    while (!MyStack.empty())
    {
        cout << MyStack.top() << " ";
        MyStack.pop();
    }
    cout << endl;
    return 0;
}