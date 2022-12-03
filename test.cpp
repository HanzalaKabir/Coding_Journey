#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
long long Power(long long n, long long x, long long r, long long res)
{
    if (x == r)
    {
        res = res * n;
        res = res % 1000000007;
        return res;
    }
    long long ans = res * n;
    x++;
    Power(n, x, r, ans);
}
long long power(long long n, long long r)
{
    long long x = 1, res = 1;
    long long ans = Power(n, x, r, res);
    return ans;
}
// long long power(int n, int r)
// {
//     long long res = 1;
//     for (int i = 1; i <= r; i++)
//     {
//         res = res * n;
//     }
//     res = res % 1000000007;
//     return res;
// }
int main()
{
    long long n, r;
    cin >> n >> r;
    long long ans = power(n, r);
    cout << ans;
    return 0;
}