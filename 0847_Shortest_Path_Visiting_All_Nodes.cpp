class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        // col = number of node
        int gsize = graph.size();
        int col = gsize;
        int row = (int)pow(2, gsize);
        
        // dist[mask][cur_node] save step of the path
        vector<vector<int>> dist(row, vector<int>(col, -1));
        queue<pair<int,int>> bfs_q;
        
        // graph have n node and we start BFS at every node simultaneously
        // ith bit in mask == 1,means ith in graph is visited
        
        for (int i = 0; i < gsize; i++) {
            int lead = i;
            int mask = 0 | (1 << i);
            
            bfs_q.push({lead, mask});
            dist[mask][lead] = 0;
        }
        
        while (!bfs_q.empty()) {
            
            int size = bfs_q.size();
            while(size--) {
                
                int cur_node = bfs_q.front().first;
                int mask = bfs_q.front().second;
                bfs_q.pop();

                // here means all bits of mask are 1
                // also means all node were visited
                if (mask == row - 1)
                    return dist[mask][cur_node];
     
                for (int i = 0;i < graph[cur_node].size();i++) {
                    int next_node = graph[cur_node][i];
                    int new_mask = mask | (1 << next_node);

                    // means the path pattern that looks like dist[new_mask][next_node] is not appeared yet
                    if (dist[new_mask][next_node] == -1){
                        dist[new_mask][next_node] = dist[mask][cur_node] + 1;
                        bfs_q.push({next_node, new_mask});
                    } 
                }
            }
        }
        // never reach here
        return 9999; 
    }  
};
