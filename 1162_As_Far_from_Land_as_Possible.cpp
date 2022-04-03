class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dis = 1;
        queue<pair<int, int>> bfs_q;
        
        //push all the 1 in to queue
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1)
                    bfs_q.push({i, j});
            }
        }

        //BFS
        while (!bfs_q.empty()) {
            
            int n = bfs_q.size();
            dis++;

            while (n--) {
                int i = bfs_q.front().first; 
                int j = bfs_q.front().second;
                bfs_q.pop();

                if(i != 0 && grid[i-1][j] == 0){
                    bfs_q.push({i-1, j});
                    grid[i-1][j] = dis;
                }
            
                
                if(i != grid.size()-1 && grid[i+1][j] == 0){
                    bfs_q.push({i+1, j});
                    grid[i+1][j] = dis;
                }
                    
                
                if(j != 0 && grid[i][j-1] == 0){
                    bfs_q.push({i, j-1});
                    grid[i][j-1] = dis;
                }
                    
                
                if(j != grid[0].size()-1 && grid[i][j+1] == 0){
                    bfs_q.push({i, j+1});
                    grid[i][j+1] = dis;
                }
            }
        }
        
        // if all 0 or all 1 in array
        if(dis - 2 <= 0)
            return -1;
        else
            return dis - 2;
    }
};
