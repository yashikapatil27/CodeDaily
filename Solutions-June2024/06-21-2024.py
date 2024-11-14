class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        l=0
        window_score=0
        satisfied=0
        max_window=0

        for r in range(len(customers)):
            if grumpy[r]:
                window_score += customers[r]
            else:
                satisfied += customers[r]

            if r-l+1 > minutes:
                if grumpy[l]:
                    window_score -= customers[l]
                l += 1

            max_window = max(window_score, max_window)
            
        return satisfied + max_window
        