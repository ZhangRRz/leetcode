class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> tmp {intervals[0][0],intervals[0][1]};
        vector<vector<int>> ans{tmp};

        for(int i = 1; i < intervals.size() ; i++){
            
            // if overlap
            if(ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else{
                tmp = {intervals[i][0],intervals[i][1]};
                ans.push_back(tmp);
            }
        }
        return ans; 
    }
};
