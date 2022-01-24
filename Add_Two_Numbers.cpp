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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_end = 0;
        int l2_end = 0;
        int now_digit = 0;
        int carry = 0;
        
        //node 
        ListNode* ans;
        ans = new ListNode;
        ListNode* nownode = ans;
            
        while(true){
            //check list one has element or not
            if(l1){
                now_digit += l1-> val;
                l1 = l1->next;
            }
            //check list two has element or not
            if(l2){
                now_digit += l2-> val;
                l2 = l2->next;
            }
            
            //carry digit use and calc
            now_digit += carry;
            carry = now_digit/10;
            now_digit %= 10;
        
            //node construct
            nownode -> val = now_digit;
            now_digit = 0;
            
            // if one of ( l1 , carry ,l2 ) has number need to calc
            // then new a node
            if(l1 || carry || l2){
                nownode -> next  = new ListNode;
                nownode = nownode -> next;
            }
                
            else{
                nownode -> next = nullptr;
                break;
            }
        }
        return ans;
    }
};
