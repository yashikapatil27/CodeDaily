# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        prev = head
        critical_pts = []
        index = 1
        curr = head.next

        while curr.next:
            if ((curr.val > prev.val) and (curr.val > curr.next.val)) or ((curr.val < prev.val) and (curr.val < curr.next.val)):
                critical_pts.append(index)

            prev = curr
            curr = curr.next
            index += 1

        if len(critical_pts) < 2:
            return [-1, -1]

        min_dist = float('inf')

        for i in range(1, len(critical_pts)):
            min_dist = min(min_dist, critical_pts[i] - critical_pts[i-1])

        max_dist = critical_pts[-1] - critical_pts[0]

        return [min_dist, max_dist]
