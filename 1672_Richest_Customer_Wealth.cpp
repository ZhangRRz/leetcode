class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int max_wea = 0;
        for(int i = 0;i < accounts.size();i++){
            int tmp = 0;
            for(int j = 0;j < accounts[i].size();j++){
                tmp += accounts[i][j];
            }
            max_wea = max(max_wea,tmp);
        }
        return max_wea;
    }
};
