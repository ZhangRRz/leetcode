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
    ListNode* middleNode(ListNode* head) {
        ListNode* onestep = head;
        ListNode* twosteps = head;
        
        while(twosteps && twosteps -> next){
            onestep = onestep -> next;
            twosteps = twosteps -> next;
            if(twosteps)
                twosteps = twosteps -> next;
        }
        
        return onestep;
    }
};
