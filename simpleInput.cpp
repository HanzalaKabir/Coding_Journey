#include <iostream>
using namespace std;
int main()
{
    int n, res[2001], sum = 0, x = 0;
    while (sum >= 0)
    {
        cin >> n;
        sum += n;
        if (sum < 0)
        {
            break;
        }
        else
        {
            res[x] = n;
            x++;
        }
    }
    for (int i = 0; i < x; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}