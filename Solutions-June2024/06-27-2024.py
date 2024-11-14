class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        max_num = max(max(edge) for edge in edges)
        freq = {}

        for edge in edges:
            for node in edge:
                if node in freq:
                    freq[node] += 1
                else:
                    freq[node] = 1
        
        for node, count in freq.items():
            if count == len(edges):
                return node
        
        return -1