#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
struct MyStack
{
    int *arr;
    int cap;
    int top1;
    int top2;
    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top1 = -1;
        top2 = cap;
    }
    void push1(int x)
    {
        if (top1 + 1 < top2)
        {
            top1++;
            arr[top1] = x;
            cout << "Element inserted in stack1" << endl;
        }
        else
        {
            cout << "No space available in stack1" << endl;
        }
    }
    void push2(int x)
    {
        if (top2 - 1 > top1)
        {
            top2--;
            arr[top2] = x;
            cout << "Element inserted in stack2" << endl;
        }
        else
        {
            cout << "No space available in stack2" << endl;
        }
    }
    int pop1()
    {
        if (top1 >= 0)
        {
            int res = arr[top1];
            top1--;
            return res;
        }
        cout << "No elements in stack" << endl;
    }
    int pop2()
    {
        if (top2 < cap)
        {
            int res = arr[top2];
            top1++;
            return res;
        }
        cout << "No elements in stack" << endl;
    }
    int peek1()
    {
        return arr[top1];
    }
    int peek2()
    {
        return arr[top2];
    }
    int size1()
    {
        return (top1 + 1);
    }
    int size2()
    {
        return (cap - top2);
    }
    bool isEmpty1()
    {
        return (top1 == -1);
    }
    bool isEmpty2()
    {
        return (top2 == cap);
    }
};
int main()
{
    MyStack s(10);
    for (int i = 0; i < 10; i++)
    {
        s.push1(5);
    }
    s.pop1();
    cout << s.peek1() << endl;
    s.push2(10);
    cout << s.peek2() << endl;
    return 0;
}