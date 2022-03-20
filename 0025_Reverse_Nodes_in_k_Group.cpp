/*
source:
https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11457/20-line-iterative-C%2B%2B-solution

*/
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head || k==1) 
            return head;
        
        int listsize = 0;
        ListNode *preheader = new ListNode(-1);
        preheader -> next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        
        while(cur = cur->next) 
            listsize++;
        
        while(listsize >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i = 1;i < k;++i) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            listsize -= k;
        }
        return preheader->next;
    }
};
