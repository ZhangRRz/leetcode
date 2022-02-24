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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lendiff = 0;
        
        ListNode *tmp = headA;
        while(tmp){
            lendiff++;
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            lendiff--;
            tmp = tmp->next;
        }
        
        // lendiff calc the length A - length B

        // B longer than A
        if(lendiff < 0) {
            swap(headA, headB);
            lendiff = 0 - lendiff; 
        }
        
        // after above if, we ensure A is longer one
        while(lendiff > 0) {
            lendiff--;
            headA = headA->next;
        }
        
        while(headA && headB) {
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
