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
    // Function to remove pair of duplicates from given string using Stack.
    string Duplicate(string s)
    {
        // Your code here
        string str;
        stack<char> check;
        check.push(s[0]);
        for (int i = 1; i <= s.length(); i++)
        {
            if (check.empty() == true)
            {
                check.push(s[i]);
                continue;
            }
            if (check.top() == s[i])
            {
                check.pop();
                continue;
            }
            else
            {
                str += s[i - 1];
                check.pop();
                check.push(s[i]);
            }
        }
        return str;
    }
    bool run(string s)
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    string removePair(string s)
    {
        string str = Duplicate(s);
        while (run(str) == false)
        {
            str = Duplicate(str);
        }
        return str;
    }
};
int main()
{
    string s;
    cout << "Enter string ";
    cin >> s;
    Solution obj;
    string ans = obj.removePair(s);
    if (ans == "")
    {
        cout << "Empty string" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}