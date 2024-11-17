class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def map_number(n:int) -> int:
            str_n = str(n)
            mapped_str = ''
            for n in str_n:
                mapped_str += str(mapping[int(n)])
            return int(mapped_str)


        mapped_nums = []
        for n in nums:
            mapped_val = map_number(n)
            mapped_nums.append((mapped_val, n))

        mapped_nums.sort(key = lambda x: x[0])

        sorted_nums = []
        for _, num in mapped_nums:
            sorted_nums.append(num)

        return sorted_nums
                