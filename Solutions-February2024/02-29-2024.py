class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        queue = deque([(root, 0)]) 
        while queue:
            prev_val = None
            level = queue[0][1]  
            level_size = len(queue)
            
            for _ in range(level_size):
                node, _ = queue.popleft()
                
                if (level % 2 == 0 and (node.val % 2 == 0 or (prev_val is not None and node.val <= prev_val))) or \
                   (level % 2 != 0 and (node.val % 2 != 0 or (prev_val is not None and node.val >= prev_val))):
                    return False
                prev_val = node.val
                
                if node.left:
                    queue.append((node.left, level + 1))
                if node.right:
                    queue.append((node.right, level + 1))
        
        return True