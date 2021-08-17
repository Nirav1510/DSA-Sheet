vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> v;
    map<int, int> a, b, c;
    for (int i = 0; i < n1; i++)
    {
        a[A[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        if (a.find(B[i]) != a.end())
        {
            b[B[i]]++;
        }
    }
    for (int i = 0; i < n3; i++)
    {
        if (b.find(C[i]) != b.end())
        {
            c[C[i]]++;
        }
    }

    for (auto i : c)
    {
        v.push_back(i.first);
    }
    return v;
}

//or

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> v;
    int prev = 0;

    for (int i = 0; i < n1; i++)
    {
        if (binary_search(B, B + n2, A[i]) && binary_search(C, C + n3, A[i]) && prev != A[i])
        {
            v.push_back(A[i]);
        }
        prev = A[i];
    }

    return v;
}