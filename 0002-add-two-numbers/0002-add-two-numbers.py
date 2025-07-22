# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        root = None
        m = root
        p = l1
        q = l2
        carry = 0
        while p or q:
            val1 = 0
            val2 = 0
            if p:
                val1 = p.val
                p = p.next
            if q:
                val2 = q.val
                q = q.next
            sum = val1 + val2 + carry
            carry = sum // 10
            newNode = ListNode(val=sum%10)
            if not root:
                root = newNode
                m = root
            else:
                m.next = ListNode(val=sum%10)
                m = m.next
        if carry:
            m.next = ListNode(val=1)
        return root


        