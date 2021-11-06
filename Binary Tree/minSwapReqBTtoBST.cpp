// first take inorder of tree then count min swaps
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> v(nums.size());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());

        int i;
        for (i = 0; i < nums.size(); i++)
        {

            if (i == v[i].second)
            {
                continue;
            }
            else
            {
                swap(v[i].first, v[v[i].second].first);
                swap(v[i].second, v[v[i].second].second);
            }
            if (i != v[i].second)
            {
                --i;
            }
            ans++;
            // i++;
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}