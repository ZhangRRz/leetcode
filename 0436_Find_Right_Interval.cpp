class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<int> ans(intervals.size());
        // map[i] : key is start of interval, value is index of interval in the input vector
        map<int, int> interv_index;
        
        for(int i = 0; i < intervals.size(); i++)
            interv_index[intervals[i][0]] = i;
        
        for(int i = 0; i < intervals.size(); i++) {
            auto it = interv_index.lower_bound(intervals[i][1]);
            
            if(it != interv_index.end()){
                ans[i] = it -> second ;
            }else{
                ans[i] = -1;
            }
        }
        return ans;
    }
};
