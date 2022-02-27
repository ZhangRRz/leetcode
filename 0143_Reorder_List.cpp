/*
source:
https://leetcode.com/problems/reorder-list/discuss/1641006/C%2B%2BPython-Simple-Solutions-w-Explanation-or-2-Pointers-O(N)-and-Inplace-O(1)-Space-Approaches
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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        for(auto iter = head; iter; iter = iter -> next)
            arr.push_back(iter);
        
		// pointers to start and end of list. Re-order in alternating fashion from both end
        int L = 1, R = size(arr)-1;
        for(int i = 0; i < size(arr); i++, head = head -> next) 
            if(i%2)                               // odd iteration:
                head -> next = arr[L++];          //        - pick node from L & update L ptr
            else                                  // even iteration
                head -> next = arr[R--];          //        - pick node from R & update R ptr
        
        head -> next = nullptr;
    }
};
