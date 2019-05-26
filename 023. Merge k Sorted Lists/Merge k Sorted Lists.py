# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        n = len(lists)
        if n == 0: return None
        while n > 1:
            k = (n + 1) / 2
            for i in range(n / 2):
                lists[i] = self.mergeTwoLists(lists[i], lists[i + k])
            
            n = k
        
        
        return lists[0]
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
        
        while l1 != None and l2 != None:
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
from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        n = len(lists)
        q = PriorityQueue(maxsize = n)
        dummy = ListNode(None)
        cur = dummy
        for node in lists:
            if node: q.put((node.val,node))
        while q.qsize() > 0:
            temp = q.get()
            cur.next = temp[1]
            cur = cur.next
            if cur.next: q.put((cur.next.val,cur.next))
            
        
        return dummy.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from queue import PriorityQueue
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        n = len(lists)
        q = PriorityQueue(maxsize = n)
        dummy = ListNode(None)
        cur = dummy
        for idx, node in enumerate(lists):
            if node: q.put((node.val,idx,node))
        while q.qsize() > 0:
            temp = q.get()
            idx, cur.next = temp[1], temp[2]
            cur = cur.next
            if cur.next: q.put((cur.next.val,idx,cur.next))
            
        
        return dummy.next
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        n = len(lists)
        return self.partion(lists, 0, n - 1)
    def partion(self, lists, start, end):
        if start > end: return None
        if start == end: return lists[start]
        mid = start + (end - start) / 2
        left = self.partion(lists, start, mid)
        right = self.partion(lists, mid + 1, end)
        return self.mergeTwoLists(left, right)
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
        
        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            
            cur = cur.next
        
        cur.next = l1 if (l1 != None) else l2
        return dummy.next
