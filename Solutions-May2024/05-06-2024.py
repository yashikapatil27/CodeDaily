class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        self.maxVal = float('-inf')
        def helper(head):
            if not head: return None
            head.next = helper(head.next)
            self.maxVal = max(self.maxVal, head.val)
            if head.val >= self.maxVal:return head
            return head.next
        return helper(head)