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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path_vec;
        
        findpath(targetSum, 0, root, path_vec, ans);
        
        return ans;
    }
    
    void findpath(int target, int pathsum,TreeNode* cur_node,vector<int>& path_vec,vector<vector<int>>& ans){
        if(!cur_node)
            return;
        
        pathsum += cur_node -> val;
        path_vec.push_back(cur_node -> val);
        
        
        findpath(target, pathsum, cur_node -> left, path_vec, ans);
        findpath(target, pathsum, cur_node -> right, path_vec, ans);
        
        if(target == pathsum && cur_node -> left == nullptr && cur_node -> right == nullptr){
            ans.push_back(path_vec);
        }
        
        path_vec.pop_back();
        return;
    
    }
};
