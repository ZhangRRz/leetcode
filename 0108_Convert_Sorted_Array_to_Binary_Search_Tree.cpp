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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size()-1;
        
        return Treebuild(0, size, nums);
    }
    
    TreeNode* Treebuild(int head, int tail, vector<int>& nums){
        
        int mid = (head + tail)/2;
        TreeNode* t;
        
        if (head == tail){
            t = new TreeNode(nums[mid]);
        }else if(head > tail){
            t = nullptr;
        }
        else{
            t = new TreeNode(nums[mid],
                             Treebuild(head, mid - 1, nums),
                             Treebuild(mid + 1, tail, nums));
        }
        return t;
    }
    
};
