map<int, pair<int, int>> m;

void solve(Node *root, int dist, int level)
{
    if (!root)
        return;
    if (!m.count(dist) || m[dist].second > level)
    {
        m[dist] = {root->data, level};
    }
    solve(root->left, dist - 1, level + 1);
    solve(root->right, dist + 1, level + 1);
}

vector<int> topView(Node *root)
{
    m.clear();
    vector<int> ans;
    solve(root, 0, 0);
    for (auto it : m)
    {
        ans.push_back(it.second.first);
    }
    return ans;
}

// Iterative

vector<int> top_view(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    map<int, char> m;

    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (m.count(dist) == 0)
            m[dist] = curr->val;

        if (curr->left != NULL)
            q.push({curr->left, dist - 1});
        if (curr->right != NULL)
            q.push({curr->right, dist + 1});
    }
    vector<int> ans;
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}