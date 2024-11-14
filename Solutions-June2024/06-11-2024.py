class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        freq = Counter(arr1)
        res = []

        for n in arr2:
            if n in freq:
                res.extend([n]*freq[n])
                del freq[n]
        
        end = sorted([n for n in freq.elements()])

        return res+end