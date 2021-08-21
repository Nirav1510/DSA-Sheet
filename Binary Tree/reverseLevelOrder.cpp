vector<int> reverseLevelOrder(Node *root)
{
    vector<int> v;
    if (!root)
        return v;
    queue<Node *> q;
    stack<int> s;

    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp->data);

        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }

    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}