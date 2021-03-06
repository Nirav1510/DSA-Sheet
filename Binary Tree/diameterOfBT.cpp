int solve(Node *root, int &res)
{
    if (!root)
        return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(l, r) + 1;
    int ans = max(temp, l + r + 1);
    res = max(res, ans);

    return temp;
}

int diameter(Node *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}