// O(nlogn)=time O(1)=space approch
// sort the array then check adjacent element

//O(n)=time and O(n)=space approch
// make a new frequency array to count frequency then check count>1 then it's duplicate element

// O(n)=time  O(1)=space

int findDuplicate(vector<int> nums)
{
    int n = nums.size();
    int slow = nums[0];
    int fast = nums[0];
    while (true)
    {

        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }
    slow = nums[0];
    while (true)
    {
        if (slow == fast)
        {
            return slow;
        }
        slow = nums[slow];
        fast = nums[fast];
    }
    return 0;
}
