class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        memo = {}

        def dp(ring_idx, key_idx):
            if key_idx == len(key):
                return 0
            if (ring_idx, key_idx) in memo:
                return memo[(ring_idx, key_idx)]

            result = float('inf')
            for i in range(len(ring)):
                if ring[i] == key[key_idx]:
                    clock = abs(ring_idx - i)
                    anticlock = len(ring) - clock
                    result = min(result, min(clock, anticlock) + dp(i, key_idx + 1))
            memo[(ring_idx, key_idx)] = result
            return result

        return dp(0, 0) + len(key)
