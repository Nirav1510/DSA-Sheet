int countOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int t = n / k;
    int ans = 0;
    for (auto it : m)
    {
        if (it.second > t)
        {
            ans++;
        }
    }
    return ans;
}