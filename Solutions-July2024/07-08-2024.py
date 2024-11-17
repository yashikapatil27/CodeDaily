class LinkedNode:
    def __init__(self, value: int):
        self.value = value
        self.next = None

class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        head = LinkedNode(1)
        curr = head

        for i in range(2, n+1):
            curr.next = LinkedNode(i)
            curr = curr.next
        
        curr.next = head
        
        while curr.next != curr:
            for _ in range(k-1):
                curr = curr.next

            curr.next = curr.next.next
        
        return curr.value