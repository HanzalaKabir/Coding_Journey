#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};
void twoStacks ::push1(int x)
{
    if (top1 + 1 == top2)
    {
        return;
    }
    top1++;
    arr[top1] = x;
    return;
}

// Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if (top2 - 1 == top1)
    {
        return;
    }
    top2--;
    arr[top2] = x;
    return;
}

// Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if (top1 == -1)
    {
        return -1;
    }
    int res = arr[top1];
    top1 = top1 - 1;
    return res;
}

// Function to remove an element from top of the stack2.
int twoStacks ::pop2()
{
    if (top2 == size)
    {
        return -1;
    }
    int res = arr[top2];
    top2 = top2 + 1;
    return res;
}
int main()
{
    twoStacks *sq = new twoStacks();
    int stack_no;
    sq->push1(5);
    sq->push2(10);
    int res = sq->pop2();
    cout << res;
    return 0;
}