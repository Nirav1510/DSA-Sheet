vector<int> preOrder(Node *root)
{
    vector<int> v;
    if (!root)
        return v;
    stack<Node *> s;

    s.push(root);
    Node *temp = root;

    while (!s.empty())
    {
        if (temp)
        {
            v.push_back(temp->data);

            if (temp->right)
                s.push(temp->right);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
        }
    }
    return v;
}