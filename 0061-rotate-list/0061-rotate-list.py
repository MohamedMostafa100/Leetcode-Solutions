# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        p = head
        q = head
        i = 0
        while i < k:
            p = p.next
            i += 1
            if not p:
                k %= i
                i = 0
                p = head
        if p == q:
            return head
        while p.next:
            p = p.next
            q = q.next
        p.next = head
        head = q.next
        q.next = None
        return head