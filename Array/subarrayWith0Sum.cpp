bool subArrayExists(int arr[], int n)
{
    unordered_map<int, bool> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || m.find(sum) != m.end() || arr[i] == 0)
        {
            return true;
        }
        else
        {
            m[sum] = true;
        }
    }
    return false;
}