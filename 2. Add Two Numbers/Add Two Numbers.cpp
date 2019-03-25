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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long num1 = 0;
        long long num2 = 0;
        long long factor = 1;
        while(l1 != nullptr || l2 != nullptr){
            num1 = ((l1 == nullptr) ? 0 : l1 -> val) * factor + num1;
            num2 = ((l2 == nullptr) ? 0 : l2 -> val) * factor + num2;
            if(l1 != nullptr){
                l1 = l1 -> next;
            }
            if(l2 != nullptr){
                l2 = l2 -> next;
            }
            
            factor *= 10;
            
        }
        long long ans = num1 + num2;
        //头结点
        ListNode ansList(-1);
        
        ListNode* pre = &ansList;
        //头插法
        /*
        while(ans){
            ListNode* temp = new ListNode(ans % 10);
            temp -> next = pre -> next;
            pre -> next = temp; 
            ans /= 10;
            
        }
        */
        //尾插法
        while(ans){
            ListNode* temp = new ListNode(ans % 10);
            
            pre -> next = temp; 
            pre = temp;
            ans /= 10;
            
        }
        
        return ansList.next;
        
        
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //头结点
        ListNode dummy(-1);
        //指向头结点的指针
        ListNode* cur = &dummy;
        //储存进位
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            if(l1 != nullptr){
                carry += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != nullptr){
                carry += l2 -> val;
                l2 = l2 -> next;
            }
            //尾插法
            ListNode* temp = new ListNode(carry % 10);
            cur -> next = temp;
            cur = temp;
            carry /= 10;
        }
        return dummy.next;
        
        
    }
};
