# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def findPath(node, target, path):
            if not node:
                return False
            
            if node.val == target:
                return True
            
            path.append("L")
            if findPath(node.left, target, path):
                return True
            path.pop()
            
            path.append("R")
            if findPath(node.right, target, path):
                return True
            path.pop()
            
            return False

        s_path = []
        t_path = []

        findPath(root, startValue, s_path)
        findPath(root, destValue, t_path)

        i = 0
        while i < len(s_path) and i < len(t_path) and s_path[i] == t_path[i]:
            i += 1

        up_moves = ["U"] * (len(s_path) - i)
        down_moves = t_path[i:]

        return "".join(up_moves + down_moves)
