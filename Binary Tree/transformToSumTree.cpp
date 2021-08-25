int sum(Node *node)
{
    if (!node)
        return 0;

    return node->data + sum(node->left) + sum(node->right);
}

void toSumTree(Node *root)
{
    if (!root)
        return;

    int l = sum(root->left);
    int r = sum(root->right);

    root->data = l + r;
    toSumTree(root->left);
    toSumTree(root->right);
}