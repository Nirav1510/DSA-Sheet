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