void solve(Node *root, Node *&head, Node *&prev)
{
    if (!root)
        return;
    solve(root->left, head, prev);

    if (!prev)
    {
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = root;
    }
    solve(root->right, head, prev);
}

Node *bToDLL(Node *root)
{
    if (!root)
        return NULL;
    Node *head = NULL, *prev = NULL;

    solve(root, head, prev);
    return head;
}