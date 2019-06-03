# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy
        cur = pre
        num = 0
        while  cur.next: 
            num += 1
            cur = cur.next
        while num >= k:
            cur = pre.next
            for i in xrange(1,k):
                t = cur.next
                cur.next = t.next
                t.next = pre.next
                pre.next = t
            
            pre = cur
            num -= k
        
        return dummy.next
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k == 1: return head
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy
        cur = head
        
        i = 1
        while cur:
            if i % k == 0:
                pre = self.reverse(pre, cur.next)
                cur = pre.next
            else:
                cur = cur.next
            i += 1
        return dummy.next
    def reverse(self, pre, next):
        last = pre.next
        cur = last.next
        while cur != next:
            last.next = cur.next
            cur.next = pre.next
            pre.next = cur
            cur = last.next
        
        
        return last
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        cur = head
        for i in xrange(k):
            if not cur: return head
            cur = cur.next
        
        new_head = self.reverse(head, cur)
        head.next = self.reverseKGroup(cur, k)
        return new_head
    def reverse(self, head, tail):
       
        pre = tail
        while head != tail:
            t = head.next
            head.next = pre
            pre = head
            head = t
            
        
        return pre
