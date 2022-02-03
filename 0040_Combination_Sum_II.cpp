class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        sort(candidates.begin(),candidates.end());
        
        csum(0, tmp,ans,candidates,target);
        
        return ans;
    }
    
    void csum(int index,vector<int>& tmp,vector<vector<int>>& ans,vector<int>& candidates,int target){
        
        for( ; index < candidates.size() ;index++ ){
            
            //if candidates[i] == candidates[i-1] means duplicate ,just ignore
            if(index-1 > -1 && candidates[index] == candidates[index-1])
                continue;

            if(target < candidates[index])
                continue;
            
            int popNum = candidates[index];
            tmp.push_back(popNum);
            candidates.erase(candidates.begin() + index);
            
            csum(index,tmp,ans,candidates,target-popNum);
            
            //insert the element we pop to keep the candidates the same in the for loop
            candidates.insert(candidates.begin() + index, popNum);
            
        }
        
        if(!target)
            ans.push_back(tmp);

        //pop_back for return the same tmp to "previoius recursion"
        if(tmp.size())
            tmp.pop_back();
    }

};
