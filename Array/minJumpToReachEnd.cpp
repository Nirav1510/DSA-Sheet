int jump(vector<int> &arr)
{
    int curr, jump, reach;
    curr = jump = reach = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (i + arr[i] > reach)
        {
            reach = i + arr[i];
        }
        if (reach == i)
            return -1;
        if (i == curr)
        {
            jump++;
            curr = reach;
        }
    }
    return jump;
}