class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        int cur = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j]){
                    find(grid,i,j,cur);
                    ans = max(cur,ans);
                    cur = 0;
                }
            }
        }
        
        return ans;
        
        
    }
    
    void find(vector<vector<int>>& grid,int i,int j,int& cur){
        if(grid[i][j] == 0)
            return;
        cur++;
        grid[i][j] = 0;// mark as traveled
        
        if(i+1 < grid.size())
            find(grid,i+1,j,cur);
        
        if(j+1 < grid[0].size())
            find(grid,i,j+1,cur);
        
        if(i-1 >= 0)
            find(grid,i-1,j,cur);
        
        if(j-1 >= 0)
            find(grid,i,j-1,cur);
            
    }
};
