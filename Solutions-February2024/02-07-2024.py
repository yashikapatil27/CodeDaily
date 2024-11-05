class Solution:
    def frequencySort(self, s: str) -> str:
        from collections import Counter
        
        freq = Counter(s)
        sorted_str = sorted(freq.keys(), key=lambda x: (-freq[x], x))
        
        result = ''.join(char * freq[char] for char in sorted_str)
        return result