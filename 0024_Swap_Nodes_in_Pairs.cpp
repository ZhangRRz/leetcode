/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        int tmp = 0;
        
        while(cur && (cur -> next)){
            tmp = cur->val;
            cur-> val = cur -> next -> val;
            cur -> next -> val = tmp;
            cur = cur -> next -> next;
        }
        
        return head;
    }
};
