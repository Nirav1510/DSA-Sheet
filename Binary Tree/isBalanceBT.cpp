int height(Node *root)
{
    if (!root)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root)
{
    if (!root)
        return true;

    if (!isBalanced(root->left) || !isBalanced(root->right))
    {
        return false;
    }
    return abs(height(root->left) - height(root->right)) <= 1 ? true : false;
}

// or

bool flag;
int check(Node *root)
{
    if (!flag || root == NULL)
    {
        return 0;
    }
    int a = check(root->left);
    int b = check(root->right);

    if (abs(a - b) > 1)
        flag = false;
    return max(a, b) + 1;
}

bool isBalanced(Node *root)
{
    flag = true;
    check(root);
    return flag;
}