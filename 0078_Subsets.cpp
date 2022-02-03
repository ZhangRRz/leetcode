class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans{{}};
        vector<int> tmp;
        
        makesubset(tmp,ans,nums);
        
        return ans;
    }
    
    
    void makesubset(vector<int>& tmp,vector<vector<int>>& ans,vector<int> nums){
        
        while(nums.size()){
            
            tmp.push_back(nums[0]);
            
            // erase the element I've choosed
            nums.erase(nums.begin());
            
            makesubset(tmp,ans,nums);
            
            ans.push_back(tmp);
            
            // pop back for next loop
            tmp.pop_back();
            
        }
    }
    
};
