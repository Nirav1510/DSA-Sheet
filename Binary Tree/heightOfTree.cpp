int height(struct Node *node)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 1;
    int l = height(node->left);
    int r = height(node->right);

    return max(l, r) + 1;
}