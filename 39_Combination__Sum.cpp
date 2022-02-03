class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
            
        
        csum(0,tmp,ans,candidates,target);  
        
        return ans;
    }
    
    void csum(int index, vector<int>& tmp, vector<vector<int>>& ans, vector<int>& candidates, int target){
        
        if(!target)
            ans.push_back(tmp);
        
        for(int i = index ; i < candidates.size() ;i++ ){

            if(target >= candidates[i]){
                
                tmp.push_back(candidates[i]);
                
                // index i is for  if this recursion pick candidates[i]
                // all the called recursion after this recurrsion can not pick 
                // candidates[0] to candidates[i-1] as option
                csum(i,tmp,ans,candidates,target-candidates[i]);
                
                
                // keep tmp the same after next for loop
                tmp.pop_back();
            }
        }

    }
};
