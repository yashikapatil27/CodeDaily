class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        common_count = Counter(words[0])

        for word in words[1:]:
            word_count = Counter(word)
            for c in common_count:
                if c in word_count:
                    common_count[c] = min(common_count[c], word_count[c])            
                else:
                    common_count[c] = 0

        res = []
        for char, freq in common_count.items():
            res.extend([char] * freq)
        
        return res