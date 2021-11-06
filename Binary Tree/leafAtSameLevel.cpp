bool flag;
void solve(Node *root, int level, int &mx)
{
    if (!root)
        return;
    if (!flag)
        return;

    if (!root->left && !root->right)
    {
        if (mx == -1)
        {
            mx = level;
        }
        else
        {
            if (level != mx)
            {
                flag = 0;
            }
        }
    }
    solve(root->left, level + 1, mx);
    solve(root->right, level + 1, mx);
}

bool check(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int mx = -1;
    flag = 1;
    solve(root, 0, mx);
    return flag;
}