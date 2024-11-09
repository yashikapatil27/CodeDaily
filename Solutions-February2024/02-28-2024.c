int findBottomLeftValue(struct TreeNode* root) {
    if (root == NULL) return 0; 

    int capacity = 1000;
    struct TreeNode** queue = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));

    int front = 0;
    int rear = 0;
    int leftmost_value = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        int level_size = rear - front;
        leftmost_value = queue[front]->val; 

        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = queue[front++];
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
    }
    
    free(queue); 
    return leftmost_value;
}
