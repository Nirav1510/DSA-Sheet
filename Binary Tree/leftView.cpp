vector<int> ans;
int maxlevel;

void solve(Node *root, int level)
{
    if (!root)
        return;

    if (level > maxlevel)
    {
        ans.push_back(root->data);
        maxlevel = level;
    }
    solve(root->left, level + 1);
    solve(root->right, level + 1);
}

vector<int> leftView(Node *root)
{
    ans.clear();
    maxlevel = -1;
    solve(root, 0);
    return ans;
}