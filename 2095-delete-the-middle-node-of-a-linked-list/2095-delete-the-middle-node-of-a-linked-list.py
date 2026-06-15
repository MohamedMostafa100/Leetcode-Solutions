# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        p = dummy
        q = dummy.next
        while q:
            q = q.next
            if not q:
                break
            q = q.next
            p = p.next
        p.next = p.next.next
        return dummy.next