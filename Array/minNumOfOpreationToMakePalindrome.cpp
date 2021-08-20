int findMinOps(int arr[], int n)
{
    int ans = 0; 
    int i=0;
    int j=n-1;
    while (i < j)
    {
        
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }

        else if (arr[i] > arr[j])
        {
            // need to merge from tail.
            j--;
            arr[j] += arr[j + 1];
            ans++;
        }

        else
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
    }

    return ans;
}