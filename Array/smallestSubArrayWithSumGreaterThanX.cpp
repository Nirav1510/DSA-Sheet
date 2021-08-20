int sb(int arr[], int n, int x)
{
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;
    while (j < n)
    {
        if (arr[j] > x)
        {
            return 1;
        }
        sum += arr[j];

        if (sum > x)
        {
            ans = min(ans, j - i + 1);
            while (sum >= x)
            {
                sum -= arr[i];
                i++;
                if (sum > x)
                    ans = min(ans, j - i + 1);
            }
        }
        j++;
    }
    return ans;
}