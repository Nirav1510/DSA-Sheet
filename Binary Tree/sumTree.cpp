int solve(Node *root)
{
    if (!root)
        return 0;
    int ll = (root->left) ? solve(root->left) : 0;
    int rr = (root->right) ? solve(root->right) : 0;

    int ans = ll + rr + root->data;

    return ans;
}

bool isSumTree(Node *root)
{
    if (!root)
        return false;

    if (!root->left && !root->right)
        return true;

    int l = solve(root->left);
    int r = solve(root->right);

    return (root->data == l + r);
}