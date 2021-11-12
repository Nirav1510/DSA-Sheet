Node *lca(Node *root, int a, int b)
{
    if (!root)
        return NULL;

    if (root->data == a || root->data == b)
    {
        return root;
    }

    Node *l = lca(root->left, a, b);
    Node *r = lca(root->right, a, b);

    if (l && r)
        return root;

    return l ? l : r;
}

int dis(Node *root, int x, int level)
{
    if (!root)
        return -1;

    if (root->data == x)
        return level;

    int l = dis(root->left, x, level + 1);

    if (l == -1)
        return dis(root->right, x, level + 1);
    return l;
}

int findDist(Node *root, int a, int b)
{
    Node *_lca = lca(root, a, b);

    int d1 = dis(_lca, a, 0);
    int d2 = dis(_lca, b, 0);

    return d1 + d2;
}