vector<int> diagonal(Node *root)
{
    vector<int> v;
    if (!root)
        return v;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        while (node)
        {
            v.push_back(node->data);
            if (node->left)
            {
                q.push(node->left);
            }
            node = node->right;
        }
    }
    return v;
}