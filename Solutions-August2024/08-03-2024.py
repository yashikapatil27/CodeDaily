class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        # if len(target) != len(arr):
        #     return False

        # target.sort()
        # arr.sort()

        # for i in range(len(target)):
        #     if target[i] != arr[i]:
        #         return False

        # return True

        count = defaultdict(int)

        for n1, n2 in zip(target, arr):
            count[n1] += 1
            count[n2] -= 1
        
        for n in count.values():
            if n != 0:
                return False
        
        return True