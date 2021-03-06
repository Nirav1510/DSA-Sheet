int findLongestConseqSubseq(int a[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i] - 1) == s.end())
        {
            int j = a[i] + 1;
            while (s.find(j) != s.end())
            {
                j++;
            }
            ans = max(ans, j - a[i]);
        }
    }
    return ans;
}