class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        def form_words(w, letter_counter):
            word_counter = Counter(w)
            for i in word_counter:
                if word_counter[i] > letter_counter[i]:
                    return False
            return True
        
        def get_score(i):
            ans = 0
            for j in i:
                ans += score[ord(j) - ord('a')]
            return ans

        letter_counter = Counter(letters)

        def backtrack(i):
            if i==len(words):
                return 0
            ans = backtrack(i+1)
            if form_words(words[i], letter_counter):
                for j in words[i]:
                    letter_counter[j] -= 1

                ans = max(ans, get_score(words[i]) + backtrack(i+1))
                for j in words[i]:
                    letter_counter[j] += 1
            return ans
        return backtrack(0)    