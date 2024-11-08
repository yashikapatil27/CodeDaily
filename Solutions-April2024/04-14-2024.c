/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int helper(struct TreeNode* node, int isLeft)
{
    if(node==NULL)
    {
        return 0;
    }

    if(node->left==NULL && node->right==NULL && isLeft)
    {
        return node->val;
    }

    return helper(node->left, 1) + helper(node->right, 0);
}
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }

    return helper(root->left, 1) + helper(root->right, 0);
}