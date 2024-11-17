class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        cycles = (n-1)*2
        time = time % cycles

        if time < n: # Forward
            return time + 1
        else:
            return n - (time - n + 1)        