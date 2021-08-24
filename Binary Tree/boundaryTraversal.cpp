bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}

void leftBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void rightBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; --i)
    {
        ans.push_back(temp[i]);
    }
}

void leaf(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        leaf(root->left, ans);
    if (root->right)
        leaf(root->right, ans);
}

vector<int> printBoundary(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    if (!isLeaf(root))
        ans.push_back(root->data);

    leftBoundary(root, ans);

    //leaftnodes

    leaf(root, ans);

    rightBoundary(root, ans);

    return ans;
}