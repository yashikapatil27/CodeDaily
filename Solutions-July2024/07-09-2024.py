class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        curr_t = 0
        total_t = 0

        for i, j in customers:
            if curr_t > i:
                total_t += curr_t - i
            else:
                curr_t = i

            total_t += j
            curr_t += j
            
        return total_t/len(customers)

        