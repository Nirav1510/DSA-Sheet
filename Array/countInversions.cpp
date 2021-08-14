#define ll long long int
ll merge(long long a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    ll l[n1], r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[i + left];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = a[i + mid + 1];
    }
    ll count = 0;
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            a[k++] = l[i++];
        }
        else
        {
            a[k++] = r[j++];
            count += (mid + 1) - (left + i);
        }
    }
    while (i < n1)
    {
        a[k++] = l[i++];
    }
    while (j < n2)
    {
        a[k++] = r[j++];
    }
    return count;
}

ll mergeSort(long long a[], int left, int right)
{
    if (left >= right)
    {
        return 0;
    }
    int mid = (left + right) / 2;
    ll count = mergeSort(a, left, mid);
    count += mergeSort(a, mid + 1, right);
    count += merge(a, left, mid, right);

    return count;
}

ll inversionCount(long long a[], long long n)
{
    return mergeSort(a, 0, (int)n - 1);
}