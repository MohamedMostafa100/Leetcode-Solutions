# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        p = head
        newHead = None
        q = newHead
        while p:
            if p.val != prev:
                newNode = ListNode(p.val)
                if not newHead:
                    newHead = newNode
                    q = newNode
                else:
                    q.next = newNode
                    q = q.next
            prev = p.val
            p = p.next
        return newHead