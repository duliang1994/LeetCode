/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode cur = pre;
        int num = 0;
        while((cur = cur.next) != null) num++;
        while(num >= k){
            cur = pre.next;
            for(int i = 1; i < k; i++){
                ListNode t = cur.next;
                cur.next = t.next;
                t.next = pre.next;
                pre.next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy.next;
    }
}
**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || k == 1) return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        
        
        ListNode pre = dummy;
        ListNode cur = head;
        
       
        for(int i = 1; cur != null; i++){
            if(i % k == 0){
                pre = reverse(pre, cur.next);
                cur = pre.next;
            } else {
                cur = cur.next;
            }
        }
        
        
        return dummy.next;
    }
    ListNode reverse(ListNode pre, ListNode next) {
        ListNode last = pre.next;
        ListNode cur = last.next;
        while(cur != next){
            last.next = cur.next;
            cur.next = pre.next;
            pre.next = cur;
            cur = last.next;
        }
        
        return last;
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode cur = head;
        for (int i = 0; i < k; ++i) {
            if (cur == null) return head;
            cur = cur.next;
        }
        ListNode new_head = reverse(head, cur);
        head.next = reverseKGroup(cur, k);
        return new_head;
    }
    public ListNode reverse(ListNode head, ListNode tail) {
       
        ListNode pre = tail;
        while(head != tail){
            ListNode t = head.next;
            head.next = pre;
            pre = head;
            head = t;
            
        }
        return pre;
    }
}
