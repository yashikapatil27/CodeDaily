# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
       
        def reverseLinkedList(head):
            prev = None
            current = head
            while current:
                next_node = current.next
                current.next = prev
                prev = current
                current = next_node
            return prev
        
        def doubleLinkedList(head):
            current = head
            carry = 0
            while current:
                current.val = current.val * 2 + carry
                carry = current.val // 10
                current.val = current.val % 10
                if not current.next and carry > 0:
                    current.next = ListNode(carry)
                    break
                current = current.next
            return head
        
        head = reverseLinkedList(head)
        head = doubleLinkedList(head)
        return reverseLinkedList(head)
