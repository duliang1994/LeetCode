/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(n--){
            fast = fast -> next;
        }
        if(fast == nullptr) return head -> next;
        
        
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete temp;
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return nullptr;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* fast = &dummy, *slow = &dummy;
        while(n--){
            fast = fast -> next;
        }
        
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete temp;
        return dummy.next;
    }
};
