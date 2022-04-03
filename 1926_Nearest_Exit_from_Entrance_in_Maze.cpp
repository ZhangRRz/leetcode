class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> next_dir = {{0,1},{0,-1},{-1,0},{1,0}};
        
        queue<pair<int,int>> bfs_q;
        // push the entrance as the start of BFS
        bfs_q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int length = 0;
        while(!bfs_q.empty()){
        
            int qsize = bfs_q.size();
            
            // bfs 
            while(qsize--){
                
                //slove 4-direction of current element
                for(int dir = 0;dir < 4;dir++){
                    
                    int next_i = next_dir[dir][0] + bfs_q.front().first;
                    int next_j = next_dir[dir][1] + bfs_q.front().second;
                    
                    
                    if(next_i < 0 || next_j < 0|| next_i >= n || next_j >= m || maze[next_i][next_j]=='+')
                        continue;
                    if(next_i == 0 || next_j == 0 || next_i == n-1 || next_j == m-1){
                            return length+1;
                    }
                    
                    bfs_q.push({next_i,next_j});
                    maze[next_i][next_j]='+';
                }

                bfs_q.pop();
                
            }
            
            length++;
            
        }

        return -1;

    }
    
};
