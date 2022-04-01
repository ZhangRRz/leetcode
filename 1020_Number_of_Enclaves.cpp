class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int ans = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                
                if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1){
                    if(grid[i][j] == 1){
                        delete_boarder(grid,i,j);
                    }
                }
            }
        }
        
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                    ans+=grid[i][j];
            }
        }
        
        
        return ans;
        
        
    }
    
    void delete_boarder(vector<vector<int>>& grid,int i,int j){
        if(grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;// mark as traveled

        
        if(i+1 < grid.size())
            delete_boarder(grid,i+1,j);
        
        if(j+1 < grid[0].size())
            delete_boarder(grid,i,j+1);
        
        if(i-1 >= 0)
            delete_boarder(grid,i-1,j);
        
        if(j-1 >= 0)
            delete_boarder(grid,i,j-1);
        
        return;
            
    }
};
