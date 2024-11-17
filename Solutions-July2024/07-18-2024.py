# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.count = 0

        def dfs(node):
            if not node:
                return []

            if not node.left and not node.right:
                return [1]

            left_dist = dfs(node.left)
            right_dist = dfs(node.right)

            for i in left_dist:
                for j in right_dist:
                    if i + j <= distance:
                        self.count += 1

            total_dist = []

            for d in left_dist + right_dist:
                if d+1 < distance:
                    total_dist.append(d+1)

            return total_dist

        dfs(root)
        return self.count