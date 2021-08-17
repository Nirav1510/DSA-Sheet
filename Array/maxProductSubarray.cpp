long long maxProduct(int *A, int n)
{
    long long int pos = A[0];
    long long int neg = A[0];
    long long int maxx = A[0];

    for (int i = 1; i < n; i++)
    {
        long long int newPos, newNeg;
        newPos = max({pos * (long long int)A[i], neg * (long long int)A[i], (long long int)A[i]});
        newNeg = min({((long long int)A[i] * pos), ((long long int)A[i] * neg), (long long int)A[i]});

        pos = newPos, neg = newNeg;
        maxx = max({maxx, pos, neg});
    }

    return maxx;
}