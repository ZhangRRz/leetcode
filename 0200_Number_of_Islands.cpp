class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int island_num = 0;
        
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[i].size();j++){
                
                //if find island;
                if(grid[i][j] == '1'){
                    
                    island_num++;
                    process_grid(i,j, grid);
                }
            }
        }
        return island_num;
    }
    
    void process_grid(int i ,int j ,vector<vector<char>>& grid){
        // turn 1 to 0 to avoid infinite recursive call
        grid[i][j] = '0';
        
        // check north south east west of '1'
        if(j+1 < grid[i].size() && grid[i][j+1] == '1')
            process_grid(i,j+1,grid);
        
        if(i+1 < grid.size() && grid[i+1][j] == '1')
            process_grid(i+1,j,grid);
        
        if(j-1 >= 0 && grid[i][j-1] == '1')
            process_grid(i,j-1,grid);
        
        if(i-1 >= 0 && grid[i-1][j] == '1')
            process_grid(i-1,j,grid);
        
        
    }
    
};
