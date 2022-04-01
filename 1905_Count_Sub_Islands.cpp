class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int ans = 0;
        bool is_sub = true;
        for(int i = 0;i < grid2.size();i++){
            for(int j = 0;j < grid2[0].size();j++){
                
                if(grid2[i][j] == 1){
                    check_boarder_island(grid1,grid2,i,j,is_sub);
                    if(is_sub)
                        ans++;
                    is_sub = true;
                }
            }
        }
        
        return ans;
        
        
    }
    
    void check_boarder_island(vector<vector<int>>& grid1,
                              vector<vector<int>>& grid2,
                              int i,int j,
                              bool& is_sub){
        if(grid2[i][j] == 0)
            return;
        
        if(is_sub && grid1[i][j] == 0)
            is_sub = false;

        grid2[i][j] = 0;// mark as traveled
        
        if(i+1 < grid2.size())
            check_boarder_island(grid1,grid2,i+1,j,is_sub);
        
        if(j+1 < grid2[0].size())
            check_boarder_island(grid1,grid2,i,j+1,is_sub);
        
        if(i-1 >= 0)
            check_boarder_island(grid1,grid2,i-1,j,is_sub);
        
        if(j-1 >= 0)
            check_boarder_island(grid1,grid2,i,j-1,is_sub);
        
        return;
            
    }
};
