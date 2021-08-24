vector<int> zigZagTraversal(Node *root)
{
    vector<int> v;
    bool flag = true;
    if (!root)
        return v;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        while (n--)
        {

            Node *node = q.front();
            q.pop();
            temp.push_back(node->data);
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
        }
        if (flag)
        {
            reverse(temp.begin(), temp.end());
            // for(int i : temp){
            //     v.push_back(i);
            // }
            v.insert(v.end(), temp.begin(), temp.end());
            flag = false;
        }
        else
        {
            // for(int i : temp){
            //     v.push_back(i);
            // }
            v.insert(v.end(), temp.begin(), temp.end());
            flag = true;
        }
        temp.clear();
    }
    return v;
}