/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
public:
    void travesal_and_sum(TreeNode* cur,bool isleftchild ,int& sum){
        if(!cur) 
            return;
        
        if(!cur->left && !cur->right && isleftchild)
            sum += cur->val;
        
        travesal_and_sum(cur->left,true,sum);
        travesal_and_sum(cur->right,false,sum);
        return;
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) 
            return 0;
        int sum = 0;
        travesal_and_sum(root,false,sum);
        
        return sum;
    }
};
