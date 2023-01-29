#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
bool matching(char a, char b)
{
    return ((a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']'));
}
bool Balanced(string str)
{
    stack<char> check;
    for (char x : str)
    {
        if (x == '(' || x == '[' || x == '{')
        {
            check.push(x);
        }
        else
        {
            if (check.empty() == true)
            {
                return false;
            }
            char temp = check.top();
            if (matching(temp, x) == false)
            {
                return false;
            }
            else
            {
                check.pop();
            }
        }
    }
    return (check.empty() == true);
}
int main()
{
    string str = "{}(())";
    if (Balanced(str))
    {
        cout << "Yes";
    }
    else
    {
        cout << "False";
    }
    return 0;
}