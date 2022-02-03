class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        sort(nums.begin(),nums.end());
        per(tmp,ans,nums);
        
        return ans;
    }
    
    void per(vector<int>& tmp,vector<vector<int>>& ans,vector<int>& nums){
        
        
        for(int i = 0 ; i < nums.size() ;i++ ){
            
            //if nums[i] == nums[i-1] means duplicate ,just ignore
            if(i-1 > -1 && nums[i] == nums[i-1])
                continue;
            
            int popNum = nums[i];
            tmp.push_back(popNum);

            nums.erase(nums.begin() + i);
            
            per(tmp,ans,nums);
            
            //insert the element we pop to keep the nums the same in the for loop
            nums.insert(nums.begin() + i, popNum);
            
        }
        
        if(!nums.size())
            ans.push_back(tmp);
        
        //pop_back for return the same tmp to "previoius recursion"
        tmp.pop_back();
    }

};
