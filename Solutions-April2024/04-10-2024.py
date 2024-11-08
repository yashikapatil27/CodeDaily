class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        n = len(deck)
        revealed = deque()
        
        for i in range(n - 1, -1, -1):
            if revealed:
                revealed.appendleft(revealed.pop())
            revealed.appendleft(deck[i])
        
        return list(revealed)
