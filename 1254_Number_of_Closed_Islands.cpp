class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        bool is_surrounded = true;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                
                if(grid[i][j] == 0){
                    check_boarder_island(grid,i,j,is_surrounded);
                    if(is_surrounded)
                        ans++;
                    is_surrounded = true;
                }
            }
        }
        
        return ans;
        
        
    }
    
    void check_boarder_island(vector<vector<int>>& grid,int i,int j,bool& is_surrounded){
        if(grid[i][j] == 1)
            return;
        if(is_surrounded)
            if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1)
                is_surrounded = false;
        
        grid[i][j] = 1;// mark as traveled
        
        if(i+1 < grid.size())
            check_boarder_island(grid,i+1,j,is_surrounded);
        
        if(j+1 < grid[0].size())
            check_boarder_island(grid,i,j+1,is_surrounded);
        
        if(i-1 >= 0)
            check_boarder_island(grid,i-1,j,is_surrounded);
        
        if(j-1 >= 0)
            check_boarder_island(grid,i,j-1,is_surrounded);
        
        return;
            
    }
};
