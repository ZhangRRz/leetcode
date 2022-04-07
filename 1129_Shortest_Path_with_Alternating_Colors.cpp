class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, 
                                         vector<vector<int>>& red_edges, 
                                         vector<vector<int>>& blue_edges){
        
        // g[i]: vector that node i connect to 
        // g[i][j] is pair : next node , edge color
        vector<vector<pair<int,int>>> gragh(n);
        
        // red_edges[i] = [a,b]
        // 0 stand for edge a to b is red
        for(int i = 0;i < red_edges.size();i++)
            gragh[red_edges[i][0]].push_back({red_edges[i][1], 0});
        
        // blue_edges[i] = [a,b]
        // 1 stand for edge a to b is blue
        for(int i = 0;i < blue_edges.size();i++)
            gragh[blue_edges[i][0]].push_back({blue_edges[i][1], 1});
        
        // size n = number of node in gragh
        // [a,b] is default to [-1,-1]
        // initial means can not reach the node i
        // a is cost reach the node i through red edge
        // b is cost reach the node i through blue edge
        vector<vector<int>> cost_from_0(n, vector<int>(2,-1));
        
        // bfs
        // pair : node i , edge_color to node i
        queue<pair<int,int>> edge_q;
        
        // start from 0 ,we can choose red start or blue start
        // because the edge from 0 to next node can be red or blue
        edge_q.push({0,0});
        edge_q.push({0,1});
        cost_from_0[0] = {0,0};
        
        while(!edge_q.empty()){
            
            int cur_node = edge_q.front().first;
            bool cur_edge_color = edge_q.front().second;
            edge_q.pop();
            
            // when we current go to node "cur_node" through "color_1" edge
            // check all node that cur_node can reach
            for(int i = 0 ;i < gragh[cur_node].size();i++){
                
                int next_node = gragh[cur_node][i].first;
                bool next_edge_color = gragh[cur_node][i].second;
                
                // 1.if cost not -1 means we already visited this node before
                // then this time must not the shortest
                
                // 2.we need different edge color
                if(cost_from_0[next_node][next_edge_color] != -1 || cur_edge_color == next_edge_color) 
                    continue;
                
                cost_from_0[next_node][next_edge_color] = 1 + cost_from_0[cur_node][cur_edge_color];
                edge_q.push({next_node, next_edge_color});
            }
        }
        vector<int> ans;
        for(int i = 0;i < cost_from_0.size();i++) {
            int cost = cost_from_0[i][0];
            
            if(cost == -1 || (cost > cost_from_0[i][1] && cost_from_0[i][1] != -1))
                cost = cost_from_0[i][1];
            
            ans.push_back(cost);
        }
        return ans;
    }
};
