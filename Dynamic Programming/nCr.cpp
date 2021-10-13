#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Solution
{
    public:
    int nCr(int n, int r)
    {   
        if (r > n)
            return 0;
        if (r == n || r == 0)
            return 1;
        ll mod = 1e9 + 7;
        ll dp[n + 1][r + 1];

        for (int j = 0; j < r + 1; j++)
            dp[0][j] = 0;
        for (int j = 0; j < n + 1; j++)
            dp[j][0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < r + 1; j++)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            }
        }
        return dp[n][r];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} 