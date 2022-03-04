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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorder_root = 0;
        return node_cons(preorder_root, 0, inorder.size()-1, preorder, inorder);
    }
    
    TreeNode* node_cons(int& preorder_root, int head, int tail,
                        vector<int>& preorder,
                        vector<int>& inorder) {
        
        if (head > tail) 
            return nullptr;
        
        int inorder_root = head;
        while(inorder[inorder_root] != preorder[preorder_root]) 
            inorder_root++;
        
        preorder_root++;
        return new TreeNode(inorder[inorder_root],
                            node_cons(preorder_root, head, inorder_root - 1, preorder, inorder),
                            node_cons(preorder_root, inorder_root + 1, tail, preorder, inorder));
    }
};
