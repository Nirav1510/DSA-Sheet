vector<int> postOrder(Node *node)
{
    vector<int> v;
    if (!node)
        return v;

    stack<Node *> s;
    s.push(node);

    stack<int> out;

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        out.push(temp->data);

        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    while (!out.empty())
    {
        v.push_back(out.top());
        out.pop();
    }
    return v;
}