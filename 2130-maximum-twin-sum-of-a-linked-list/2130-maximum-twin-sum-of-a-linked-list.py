# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        res = 0
        p = head
        q = head.next
        while q.next:
            q = q.next.next
            temp = p.next
            p.next = p.next.next
            temp.next = head
            head = temp
        p = p.next
        q = head
        while p:
            res = max(res, p.val + q.val)
            p = p.next
            q = q.next
        return res
        