map<Node *, int> mp;
int sumGrandChildren(Node *node)
{
    int sum = 0;

    if (node->left)
    {
        sum += solve(node->left->left) + solve(node->left->right);
    }
    if (node->right)
    {
        sum += solve(node->right->left) + solve(node->right->right);
    }
    return sum;
}

int solve(Node *root)
{
    if (!root)
        return 0;

    if (mp.find(root) != mp.end())
        return mp[root];
    // case 1
    int include = root->data + sumGrandChildren(root);
    // case 2
    int exclude = solve(root->left) + solve(root->right);

    return mp[root] = max(include, exclude);
}

int getMaxSum(Node *root)
{
    if (!root)
        return 0;
    mp.clear();
    return solve(root);
}