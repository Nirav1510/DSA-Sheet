vector<int> inOrder(Node *root)
{
    vector<int> v;
    stack<Node *> s;
    Node *temp = root;

    while (!s.empty() || temp)
    {
        if (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            v.push_back(temp->data);
            temp = temp->right;
        }
    }
    return v;
}