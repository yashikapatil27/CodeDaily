struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
    if (depth == 1) 
    {
        struct TreeNode* newRoot = createNode(val);
        newRoot->left = root;
        return newRoot;
    }

    void dfs(struct TreeNode* node, int curr_depth) 
    {
        if (node == NULL)
            return;
        if (curr_depth == depth - 1) {
            struct TreeNode* newLeft = createNode(val);
            struct TreeNode* newRight = createNode(val);
            newLeft->left = node->left;
            newRight->right = node->right;
            node->left = newLeft;
            node->right = newRight;
        } 
        else 
        {
            dfs(node->left, curr_depth + 1);
            dfs(node->right, curr_depth + 1);
        }
    }

    dfs(root, 1);
    return root;
}

