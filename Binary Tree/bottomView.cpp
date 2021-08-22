//recursive

map<int, pair<int, int>> mp; //{node,level}

void solve(Node *node, int dist, int level)
{
    if (node == NULL)
        return;
    if (mp.count(dist) == 0 || mp[dist].second <= level)
        mp[dist] = make_pair(node->data, level);

    solve(node->left, dist - 1, level + 1);
    solve(node->right, dist + 1, level + 1);
}

vector<int> bottomView(Node *root)
{
    mp.clear();
    solve(root, 0, 0);
    vector<int> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second.first);
    }
    return ans;
}

// iterative

vetor<int> bottom_view(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    map<int, int> m;

    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        m[dist] = curr->val;

        if (curr->left)
            q.push({curr->left, dist - 1});
        if (curr->right)
            q.push({curr->right, dist + 1});
    }
    vector<int> ans;
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}