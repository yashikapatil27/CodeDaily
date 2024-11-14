# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes = []
        dfs(root, nodes)

        return sort_array_to_bst(nodes, 0, len(nodes)-1)
    
def dfs(node, nodes):
    if not node:
        return
        
    dfs(node.left, nodes)
    nodes.append(node)
    dfs(node.right, nodes)

def sort_array_to_bst(nodes, start, end):
    if start > end:
        return None

    mid = (start+end)//2

    root = nodes[mid]

    root.left = sort_array_to_bst(nodes, start, mid-1)
    root.right = sort_array_to_bst(nodes, mid+1, end)

    return root