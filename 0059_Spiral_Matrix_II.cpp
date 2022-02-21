class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int bound = n*n;
        vector<vector<int>> ans;
        for(int i  = 0; i < n;i++){
            ans.push_back({});
            for(int j = 0; j < n;j++)
                ans[i].push_back(0);
        }
        
        int i = 0;
        int j = 0;
        int now = 1;
        
        while(now <= bound){
            
            // 1. horizonal, left to right
            while(j < n && ans[i][j] == 0 ){
                ans[i][j] = now;
                now++;
                j++;
            }
            j--;
            i++;
            
            // 2. vertical, top to bottom
            while(i < n && ans[i][j] == 0 ){
                ans[i][j] = now;
                now++;
                i++;
            }
            i--;
            j--;

            // 3. horizonal, right to left 
            while(j >= 0 && ans[i][j] == 0 ){
                ans[i][j] = now;
                now++;
                j--;
            }
            j++;
            i--;

            // 4. vertical, bottom to  top 
            while(i >= 0 && ans[i][j] == 0 ){
                ans[i][j] = now;
                now++;
                i--;
            }
            i++;
            j++;

        }
        
        return ans;
        
    }
};
