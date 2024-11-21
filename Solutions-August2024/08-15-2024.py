class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        total = 0
        five = 0
        ten = 0
        twenty = 0
        
        for bill in bills:
            if bill == 5:
                five += 1
                total += 5
            elif bill == 10:
                if five == 0:
                    return False
                five -= 1
                ten += 1
            else:
                if ten > 0 and five > 0:
                    ten -= 1
                    five -= 1
                    twenty += 1
                elif five >= 3:
                    five -= 3
                    twenty += 1
                else:
                    return False
        
        return True