void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;
    //find peak's left element 
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }
    if (i >= 0)
    {
        int j = n - 1;
        //find the element in from end that is greater than peak's left element 
        while (j >= 0 && nums[i] >= nums[j])
        {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}