#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int n, y;
    cin >> n;
    int k = -2, i = 0;
    for (i; i <= (2 * n - 1) / 2; i++)
    {
        if (i == 0)
        {
            k = k + 1;
        }
        else
        {
            k = k + 2;
        }
        for (int j = 0; j <= (2 * n - 1); j++)
        {
            if (n - j == i)
            {
                y = j + 1;
                for (int l = 0; l < k; l++)
                {
                    cout << " ";
                    j++;
                }
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    i++;
    for (i; i <= (2 * n - 1); i++)
    {
        k = k - 2;
        for (int j = 0; j <= (2 * n - 1); j++)
        {
            if (j == y)
            {
                if (i == (2 * n - 1))
                {
                    continue;
                }
                y = j + 1;
                for (int l = 0; l < k; l++)
                {
                    cout << " ";
                    j++;
                }
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}