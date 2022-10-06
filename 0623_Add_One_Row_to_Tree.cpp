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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        // depth == 1, means insert node as parent of root
        if(depth == 1)
            return new TreeNode(val,root,nullptr);

        // use dfs to find all the node at depth-1
        dfs(root,val,depth-1);
        return root;
    }

    void dfs(TreeNode* cur, int val, int depth){
        
        if(!cur)
            return;

        // means we are at target depth
        if(depth == 1){
            cur -> left = new TreeNode(val,cur -> left,nullptr);
            cur -> right = new TreeNode(val,nullptr,cur -> right);
        }

        // need to traversal deeper
        dfs(cur -> left,val,depth-1);
        dfs(cur -> right,val,depth-1);

        return;
    }


};
