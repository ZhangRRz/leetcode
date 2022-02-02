// source of the answer
/*

https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/1063734/C%2B%2B-Optimised-BFS-vs.-DFS-Fastest-Solution-to-Date-Explained-100-Time-~99-Space

*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // start or end == 1 means cannot access
        if (grid[0][0] || grid[grid.size()-1][grid.size()-1]) return -1;
        

        int path_lenght = 2, qsize = 1;
        int maxX = grid[0].size() - 1, maxY = grid.size() - 1;
        
        queue<pair<int, int>> q;
        // if grid only looks like [[0 or 1]]
        if (!maxX && !maxY) 
            return (grid[maxX][maxY] == 0)? 1 : -1;
        
        // adding the starting point
        q.push({0, 0});
        qsize = q.size();
        
        // marking start as visited
        grid[0][0] = -1;
        while (qsize) {
            while (qsize--) {
                
                // reading and popping the coordinates on the front of the queue
                auto [currentx, currenty] = q.front();
                q.pop();
                
                // x will between currentx - 1 and currentx + 1 ,and so dose y
                // so it means all the neighboor of grid[currentx][currenty]
                for (int x = max(0, currentx - 1), lmtX = min(currentx + 1, maxX); x <= lmtX; x++) {
                    for (int y = max(0, currenty - 1), lmtY = min(currenty + 1, maxY); y <= lmtY; y++) {
                        // check if we reached the target
                        if (x == maxX && y == maxY) return path_lenght;
                        // marking it as visited and adding it to the q if it was still a valid cell( == 0)
                        if (grid[y][x] == 0) {
                            grid[y][x] = -1;
                            q.push({x, y});
                        }
                    }
                }
            }
            // so every time that the above loop over
            // means all the position that need "path_lenght" steps to reach from start point
            // already checked
            
            
            // preparing for the next loop
            path_lenght++;
            qsize = q.size();
        }
        return -1;
    }
};
