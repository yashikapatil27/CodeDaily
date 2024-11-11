class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        moves = 0
        
        def dfs(node):
            nonlocal moves
            if not node:
                return 0
            
            left_excess = dfs(node.left)
            right_excess = dfs(node.right)
            excess_coins = node.val + left_excess + right_excess - 1
            
            moves += abs(excess_coins)
            
            return excess_coins
        
        dfs(root)
        return moves
