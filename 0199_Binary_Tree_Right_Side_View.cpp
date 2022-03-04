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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        vector<TreeNode*> tmp;
        tmp.push_back(root);
        
        while(tmp.size()){
            ans.push_back(tmp.back() -> val);
            
            int n = tmp.size();
            while(n--){
                if(tmp[0] -> left)
                    tmp.push_back(tmp[0] -> left);
                if(tmp[0] -> right)
                    tmp.push_back(tmp[0] -> right);
                tmp.erase(tmp.begin());
            }
        }
        return ans;
    }
};
