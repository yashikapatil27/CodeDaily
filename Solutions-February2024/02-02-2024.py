class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        result = []

        for length in range(len(str(low)), len(str(high)) + 1):
            for start in range(10 - length + 1):
                num = digits[start: start + length]
                num = int(num)

                if low <= num <= high and num not in result:
                    result.append(num)

        return result
