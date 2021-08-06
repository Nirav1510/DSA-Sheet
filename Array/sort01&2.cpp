void sort012(int A[], int n)
{
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (A[j] == 0)
            swap(A[i++], A[j]);
        if (A[j] == 2)
            swap(A[j], A[k--]);
        else
            j++;
    }
}