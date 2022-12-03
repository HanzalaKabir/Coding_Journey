#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int Char = 256;
vector<int> Leftmost(string &str, string &check)
{
    vector<int> res;
    if (str.length() < check.length())
    {
        res.push_back(-1);
        return res;
    }
    int j = 0, i = 0;
    int k = i + 1;
    // Include all the commented lines to change the program for same elements also and when the lines are not included it works
    // only for distinct elements.
    while (i < str.length()) //&& k < str.length()
    {
        if (j == check.length())
        {
            res.push_back(i - j);
            j = 0;
            // i = k;
            k++;
        }
        if (str[i] == check[j])
        {
            i++;
            j++;
        }
        else
        {
            if (i > (str.length() - check.length()))
            {
                cout << "I returned" << endl;
                return res;
            }
            j = 0;
            i++;
            k++;
        }
    }
    if (j == check.length())
    {
        res.push_back(i - j);
        j = 0;
    }
    return res;
}
int main()
{
    string str;
    string check;
    cin >> str;
    cin >> check;
    vector<int> res = Leftmost(str, check);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}