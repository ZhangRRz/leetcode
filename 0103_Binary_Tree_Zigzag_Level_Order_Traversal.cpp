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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;

        vector<TreeNode*> tree_ptr;
        tree_ptr.push_back(root);
        
        while(!tree_ptr.empty()){

            vector<int> tmp;
            for (int i = tree_ptr.size()-1; i >= 0; i--) {
                tmp.push_back(tree_ptr[i] -> val);
                
                // left child first then right child
                if(tree_ptr[i] -> left)
                    tree_ptr.push_back(tree_ptr[i] -> left);
                if(tree_ptr[i] -> right)
                    tree_ptr.push_back(tree_ptr[i] -> right);
                
                
                tree_ptr.erase(tree_ptr.begin() + i);

            }
            ans.push_back(tmp);
            tmp.clear();
            
            for (int i = tree_ptr.size()-1; i >= 0; i--) {
                tmp.push_back(tree_ptr[i] -> val);
                
                // right child first then left child
                if(tree_ptr[i] -> right)
                    tree_ptr.push_back(tree_ptr[i] -> right);
                if(tree_ptr[i] -> left)
                    tree_ptr.push_back(tree_ptr[i] -> left);

                tree_ptr.erase(tree_ptr.begin() + i);

            }
            if(tmp.size())
                ans.push_back(tmp);
        }
        return ans;
    }
};
