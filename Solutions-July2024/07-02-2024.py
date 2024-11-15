class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        freq1 = Counter(nums1)
        freq2 = Counter(nums2)
        res = []

        for num in freq1:
            if num in freq2:
                res.extend([num]*min(freq1[num], freq2[num]))

        
        return res