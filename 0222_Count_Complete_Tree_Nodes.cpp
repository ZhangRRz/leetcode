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
    int countNodes(TreeNode* root) {
        if(!root) 
            return 0;
        int num = 1;
        
        TreeNode *curR = root->left, *curL = root->left;
        
        while(curR){
            curL = curL->left;
            curR = curR->right;
            num = num << 1;
        }
        return  num + ( !curL ? countNodes(root->right) : countNodes(root->left) );
    }
};
