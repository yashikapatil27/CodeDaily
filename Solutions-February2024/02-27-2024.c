/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int calculate_diameter(struct TreeNode* current, int* max_diameter)
{
    if(current==NULL)
    {
        return 0;
    }
    int left_depth = calculate_diameter(current->left, max_diameter);
    int right_depth = calculate_diameter(current->right, max_diameter);

    *max_diameter = max(*max_diameter, left_depth + right_depth);
    return max(left_depth, right_depth)+1;

} 

int diameterOfBinaryTree(struct TreeNode* root) {
    int max_diameter = 0;
    calculate_diameter(root, &max_diameter);
    return max_diameter;
}