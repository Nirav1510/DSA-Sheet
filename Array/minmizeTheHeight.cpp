int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int res = arr[n - 1] - arr[0];
    int minele, maxele;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= k && arr[n - 1] >= k)
        {
            minele = min(arr[0] + k, arr[i] - k);
            maxele = max(arr[i - 1] + k, arr[n - 1] - k);
            res = min(res, maxele - minele);
        }
    }
    return res;
}