class Solution
{
public:
    unordered_map<int, int> mp;
    int idx;

    Node *build(int pre[], int s, int e)
    {
        if (s > e)
            return NULL;

        Node *root = new Node(pre[idx]);
        idx++;

        root->left = build(pre, s, mp[root->data] - 1);
        root->right = build(pre, mp[root->data] + 1, e);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        mp.clear();
        idx = 0;
        for (int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
        return build(pre, 0, n - 1);
    }
};