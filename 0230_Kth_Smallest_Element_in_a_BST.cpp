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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        treetraversal(root,k,ans);
        return ans;
    }
    /*
    key idea is traversal like inorder
    leftchild must small than current node
    so count left subtree first ,then count current node ,and then right subtree

    */
    void treetraversal(TreeNode* cur,int& k,int& ans){
        if(!cur)
            return;
        
        treetraversal(cur->left,k,ans);
        // here can increase a new val "count" or just decrease the "k" that problem gives;
        k--;
        // once k == 0 means current node is the answer
        if(!k)
            ans = cur -> val;
        
        treetraversal(cur->right,k,ans);
        
        return;
    }
};
