class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionary.sort(key=len)
        
        def replace_word(word):
            for root in dictionary:
                if word.startswith(root):
                    return root
            return word
        
        words = sentence.split()
        replaced_words = [replace_word(word) for word in words]
        
        return ' '.join(replaced_words)
