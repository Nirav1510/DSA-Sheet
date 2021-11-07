Node *lca(Node *root, int a, int b)
{
    if (!root)
        return nullptr;

    if (root->data == a || root->data == b)
    {
        return root;
    }

    Node *l = lca(root->left, a, b);
    Node *r = lca(root->right, a, b);

    if (l && r)
        return root;
    return (l) ? l : r;
}
}
;