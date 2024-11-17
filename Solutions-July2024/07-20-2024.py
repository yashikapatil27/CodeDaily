class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        rows, cols = len(rowSum), len(colSum)

        res = [[0]* cols for _ in range(rows)]

        for i in range(rows):
            res[i][0] = rowSum[i]

        for j in range(cols):
            curr_col_sum = 0

            for i in range(rows):
                curr_col_sum += res[i][j]

                r = 0
                while curr_col_sum > colSum[j]:
                    diff = curr_col_sum - colSum[j]
                    shift = min(diff, res[i][j])
                    res[i][j] -= shift
                    res[i][j+1] += shift
                    curr_col_sum -= shift
                    r += 1
        return res
