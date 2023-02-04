#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
vector<string> recursive(int arr[], int n, int i, int k, int j, vector<string> dig)
{
    if (k == n)
    {
        vector<string> res;
        return res;
    }
    vector<string> res;
    string str;
    while (j < n)
    {
        str += dig[i][j];
        cout << str;
        vector<string> temp = recursive(arr, n, arr[k + 1], k + 1, j, dig);
        str += temp[0];
        if (i != arr[0])
        {
            res.push_back(str);
            return res;
        }
        else
        {
            res.push_back(str);
            j++;
        }
    }
    res.push_back(str);
    return res;
}
vector<string> possibleWords(int arr[], int n)
{
    vector<string> dig = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int k = 0, j = 0;
    int i = arr[k];
    cout << i << endl;
    vector<string> res = recursive(arr, n, i, k, j, dig);
    return res;
}
int main()
{
    int arr[] = {2, 3, 4};
    int n = 3;
    vector<string> res = possibleWords(arr, n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}