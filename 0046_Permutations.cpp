class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp ;
        vector<vector<int>> ans;
        per(nums,tmp,ans);
        
        return ans;
    }
    
    void per(vector<int> nums,vector<int> tmp ,vector<vector<int>>& ans){
        if(nums.empty()){
            ans.push_back(tmp);
            return;
        }
        vector<int> cur = nums;
        for(int i = 0;i < nums.size();i++){
            tmp.push_back(cur[i]);
            cur.erase(cur.begin() + i);
            
            per(cur,tmp,ans);
            
            tmp.pop_back();
            cur = nums;
        }
    } 
};
