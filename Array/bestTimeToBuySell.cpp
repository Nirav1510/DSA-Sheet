// DP based solution
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> dp(n, 0);
    int maxProfit = 0;
    int i = n - 2;
    while (i >= 0)
    {
        dp[i] = max(dp[i + 1], prices[i + 1]);
        maxProfit = max(dp[i] - prices[i], maxProfit);
        i--;
    }
    return maxProfit;
}

// Intution
int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;

    int profit = 0;
    int minele = INT_MAX;

    for (int p : prices)
    {
        minele = min(minele, p);
        profit = max(profit, p - minele);
    }
    return profit;
}