class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        n = len(heights)
        heights_saved = heights.copy()
        heights.sort()
        count=0

        for i in range(n):
            if heights[i] != heights_saved[i]:
                count += 1
        
        return count
