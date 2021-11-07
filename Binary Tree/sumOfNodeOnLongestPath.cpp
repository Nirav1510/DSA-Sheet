int res, maxlevel;
void solve(Node *root, int level, int sum)
{
    if (!root) return;
    sum += root->data;
    if (level > maxlevel)
    {
        res = sum;
        maxlevel = level;
    }
    else if (level == maxlevel)
    {
        res = max(res, sum);
    }
    solve(root->left, level + 1, sum);
    solve(root->right, level + 1, sum);
}
int sumOfLongRootToLeafPath(Node *root)
{
    res = 0, maxlevel = -1;
    solve(root, 0, 0);
    return res;
}