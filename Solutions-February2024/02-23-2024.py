class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        dp = [float('inf')] * n
        dp[src] = 0

        for _ in range(k + 1):
            temp = dp[:]  
            for u, v, price in flights:
                temp[v] = min(temp[v], dp[u] + price)
            dp = temp

        return dp[dst] if dp[dst] < float('inf') else -1
