/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if(root->left == NULL)
    {
        return root->val == 1;
    }

    bool rightRes = evaluateTree(root->right);
    bool leftRes = evaluateTree(root->left);

    if(root->val == 2)
    {
        return rightRes || leftRes;
    }
    if(root->val == 3)
    {
        return rightRes && leftRes;
    }

    return (root->val==0) ? false : true;
}