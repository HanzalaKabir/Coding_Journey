#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const char a = '1';
long binarySubstring(int n, string str)
{
    long count = 0;
    int k = 0, p = 0;
    for (int i = k; i < n; i++)
    {
        if (str[i] == a)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (p == 0 && str[j] == a)
                {
                    k = j;
                    count++;
                    p++;
                }
                else if (str[j] == a)
                {
                    count++;
                }
            }
            p = 0;
        }
    }
    return count;
}
int main()
{
    string str = "11111";
    int n = 5;
    long res = binarySubstring(n, str);
    cout << res;
    return 0;
}