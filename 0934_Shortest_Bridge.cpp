class Solution {
public:
    
    int shortestBridge(vector<vector<int>>& grid) {

        int x = 0;
        int y = 0;
        
        // stop at first 1 we meet
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j]){
                    x = i;
                    y = j;
                    break;
                }
            }
            if(grid[x][y])
                break;
        }

        queue<pair<int,int>> bfs_q;
        // this change all the value of first island to 2
        // and push all most outside '2' of island in to bfs queue
        dfs_find_first_island(grid,x,y,bfs_q);
        
        int step = 2;
        while(!bfs_q.empty()){
            
            int n = bfs_q.size();
            while(n--){
                int i = bfs_q.front().first;
                int j = bfs_q.front().second;
                bfs_q.pop();
                

                if(i-1 >= 0 && grid[i-1][j] < step-1){
                    if(grid[i-1][j] == 1)
                        return step-2;
                    grid[i-1][j] = step+1;
                    bfs_q.push({i-1,j});
                }

                if(j-1 >= 0 && grid[i][j-1] < step-1){
                    if(grid[i][j-1] == 1)
                        return step-2;
                    grid[i][j-1] = step+1;
                    bfs_q.push({i,j-1});
                }

                if(i+1 < grid.size() && grid[i+1][j] < step-1){
                    if(grid[i+1][j] == 1)
                        return step-2;
                    grid[i+1][j] = step+1;
                    bfs_q.push({i+1,j});
                }
                

                if(j+1 < grid[0].size() && grid[i][j+1] < step-1){
                    if(grid[i][j+1]  == 1)
                        return step-2;
                    grid[i][j+1] = step+1;
                    bfs_q.push({i,j+1});
                }
                
            }
         
            step++;
        }
        
        return -1;
        
        
    }
    
    void dfs_find_first_island(vector<vector<int>>& grid,int i,int j, queue<pair<int,int>>& bfs_q){
        
        grid[i][j] = 2;
        
        // to check grid[i][j] is near 0 or not 
        // if near 0 ,means grid[i][j] is most outside of island
        bool near_zero = false;
        
        if(i-1 >= 0){
            near_zero = near_zero || !grid[i-1][j];
            if(grid[i-1][j])
                dfs_find_first_island(grid,i-1,j,bfs_q);
        }

        
        if(j-1 >= 0){
            near_zero = near_zero || !grid[i][j-1];
            if(grid[i][j-1] == 1)
                dfs_find_first_island(grid,i,j-1,bfs_q);
        }

        
        if(i+1 < grid.size()){
            near_zero = near_zero || !grid[i+1][j];
            if(grid[i+1][j] == 1)
                dfs_find_first_island(grid,i+1,j,bfs_q);
        }
            
        
        if(j+1 < grid[i].size()){
            near_zero = near_zero || !grid[i][j+1];
            if(grid[i][j+1] == 1)
                dfs_find_first_island(grid,i,j+1,bfs_q);
        }
        
        if(near_zero)
            bfs_q.push({i,j});
        
        
        return;
    }
};
