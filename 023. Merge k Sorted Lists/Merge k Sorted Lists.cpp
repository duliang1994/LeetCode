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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        ListNode* ans = lists[0];
        for(int i = 1; i < n; i++){
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
        
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        while(n > 1){
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
        
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
struct cmp {
    bool operator() (const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }  
};

class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, cmp> q;
        for(auto l : lists){
            if(l) q.push(l);
        }
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            cur->next = temp;
            cur = cur->next;
            if(cur->next) q.push(cur->next);
        }
        return dummy.next;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return partion(lists, 0, n - 1);
    }
    ListNode* partion(vector<ListNode*>& lists, int start, int end) {
        if(start < end) return nullptr;
        if(start == end) return lists[start];
        int mid = start + (end - start) / 2;
        ListNode* left = partion(lists, start, mid);
        ListNode* right = partion(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
        
    }
};
