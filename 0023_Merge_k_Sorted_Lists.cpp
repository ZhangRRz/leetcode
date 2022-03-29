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

/*
example :
vector<ListNode *> &lists have 9 lists
remaining_list = 9
merge lists[0],lists[1] ,put result to lists[0] ,then 1, becomes useless
merge lists[2],lists[3] ,put result to lists[1] ,then 2,3 become useless
merge lists[4],lists[5] ,put result to lists[2] ,then 3,4,5 become useless
merge lists[6],lists[7] ,put result to lists[3] ,then 4,5,6,7 become useless
but now lists[8] still not be merged, so put it to index = remaining_list/2 = 4
and update remaining_list = 5, start while loop again
.
.
.

after while loop break
lists[0] is answer, just return
*/


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return nullptr;
        
        int remaining_list = lists.size();
        
        while(remaining_list > 1){
            for(int i = 0; i < remaining_list / 2; i++) {
                ListNode *merged_result = mergeTwoLists(lists[2*i], lists[2*i+1]);
                lists[i] = merged_result;
            }
            // current number of list is odd, means the last list still not be merged
            if(remaining_list%2 == 1) {
                lists[remaining_list/2] = lists[remaining_list - 1];
                remaining_list = remaining_list/2+1;
            } else {
                remaining_list = remaining_list/2;
            }
        }
        return lists.front();
    }
    
    // Q21. merge 2 list
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
