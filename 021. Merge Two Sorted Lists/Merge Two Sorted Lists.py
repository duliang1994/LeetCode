# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:  return l2
        if l2 == None:  return l1
        dummy = ListNode(-1)
        cur = dummy
        
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            
            cur = cur.next
        
        cur.next = l1 if (l1 != None) else l2
        return dummy.next
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:  return l2
        if l2 == None:  return l1
        
        
        if l1.val <= l2.val:
                l1.next = self.mergeTwoLists(l1.next, l2)
                return l1
        else:
                l2.next = self.mergeTwoLists(l1, l2.next)
                return l2
