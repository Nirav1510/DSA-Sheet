int maxSubarraySum(int arr[], int n)
{
    int sum = 0, maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = max(sum += arr[i], arr[i]);
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}