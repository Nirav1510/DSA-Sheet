int checkMirrorTree(int n, int e, int A[], int B[])
{
    map<int, vector<int>> v1, v2;
    for (int i = 0; i < 2 * e; i += 2)
    {
        v1[A[i]].push_back(A[i + 1]);
    }
    for (int i = 0; i < 2 * e; i += 2)
    {
        v2[B[i]].push_back(B[i + 1]);
    }
    for (auto it : v1)
    {
        auto t = it.second;
        reverse(t.begin(), t.end());
        v1[it.first] = t;
    }
    return v1 == v2;
}