class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        def good(min_dist):
            count = 1
            last_position = position[-1]

            for i in range(1, len(position)):
                if position[i] - last_position >= m:
                    count += 1
                    last_position = position[i]
                if count >= m:
                    return True
            return False


        position.sort()
        left, right = 1, position[-1] - position[0]

        res = 0
        while left<=right:
            mid=(left+right)//2
            if good(mid):
                res = mid
                left = mid+1
            else:
                right = mid-1

        return res