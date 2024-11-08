/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int current_sum, int* total_sum)
{
    if(root==NULL)
    {
        return;
    }

    current_sum = current_sum*10 + root->val;

    if(root->left==NULL && root->right==NULL)
    {
        *total_sum += current_sum;
        return;
    }

    dfs(root->left, current_sum, total_sum);
    dfs(root->right, current_sum, total_sum);
}

int sumNumbers(struct TreeNode* root) {
    int total_sum=0;
    dfs(root, 0, &total_sum);

    return total_sum;
}