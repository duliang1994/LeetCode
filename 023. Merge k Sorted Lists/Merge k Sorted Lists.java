/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;
        if(n == 0) return null;
        while(n > 1){
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        
        return lists[0];
    }
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                cur.next = l1;
                l1 = l1.next;
            } else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        cur.next = (l1 != null) ? l1 : l2;
        return dummy.next;
        
    }
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0) return null;
        PriorityQueue<ListNode> q = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1, ListNode o2){
                return o1.val - o2.val;
            }
        });
        for(ListNode l : lists){
            if(l != null) q.add(l);
        }
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        while(!q.isEmpty()){
            ListNode temp = q.peek();
            q.poll();
            cur.next = temp;
            cur = cur.next;
            if(cur.next != null) q.add(cur.next);
        }
        return dummy.next;
    }
    
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;
        return partion(lists, 0, n - 1);
    }
    public ListNode partion(ListNode[] lists, int start, int end) {
        if(start > end) return null;
        if(start == end) return lists[start];
        int mid = start + (end - start) / 2;
        ListNode left = partion(lists, start, mid);
        ListNode right = partion(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                cur.next = l1;
                l1 = l1.next;
            } else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        cur.next = (l1 != null) ? l1 : l2;
        return dummy.next;
        
    }
}
