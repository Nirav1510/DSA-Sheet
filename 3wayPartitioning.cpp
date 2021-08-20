void threeWayPartition(vector<int> &v, int a, int b)
{
    //variation of dutch national flag problem
    int n = v.size();
    int low = 0, high = n - 1, mid = 0;

    while (mid <= high)
    {
        if (v[mid] < a)
        {
            swap(v[mid], v[low]);
            low++;
            mid++;
        }
        else if (v[mid] > b)
        {
            swap(v[mid], v[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}