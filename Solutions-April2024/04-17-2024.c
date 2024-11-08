/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct Solution{
    char* (*smallestFromLeaf)(struct TreeNode* root);
}Solution;

char* helper(struct TreeNode* root, char* curr)
{
    if(root==NULL)
    {
        return NULL;
    }

    char* new_curr = (char*)malloc(2*sizeof(char));
    new_curr[0] = (char)('a' + root->val);
    new_curr[1] = '\0';

    char* updated_curr = (char*)malloc((strlen(new_curr)+strlen(curr)+1)*sizeof(char));
    strcpy(updated_curr, new_curr);
    strcat(updated_curr, curr);

    free(new_curr);

    if(root->left && root->right)
    {
        char* left_res = helper(root->left, updated_curr);
        char* right_res = helper(root->right, updated_curr);
        return strcmp(left_res, right_res)<0 ? left_res: right_res;
    }
    else if(root->left)
    {
        return helper(root->left, updated_curr);
    }
    else if(root->right)
    {
        return helper(root->right, updated_curr);
    }
    else
    {
        return updated_curr;
    }

}

char* smallestFromLeaf(struct TreeNode* root)
{
    return helper(root, "");
}