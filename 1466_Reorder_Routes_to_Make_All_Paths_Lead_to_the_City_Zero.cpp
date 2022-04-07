class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        // connect_node[i][j] means edge from node i to node j
        // but if connect_node[i][j] < 0 ,means edge from node j to node i
        vector<vector<int>> connect_node(n);
        
        for(int i = 0;i < connections.size();i++){
            
            // [a,b] is a to b 
            connect_node[connections[i][0]].push_back(connections[i][1]);
            // use -edge to note this edge is a to b ,not b to a
            connect_node[connections[i][1]].push_back(connections[i][0]*-1);
        }
        
        
        return dfs(connect_node,-1,0);
        
    }
    /*
    because of  Constraints:connections.length == n - 1
    we can know there is no ring in graph
    */
    
    int dfs(vector<vector<int>>& connect_node,int prev_node,int cur_node){
        
        int tmp = 0;
        cur_node = abs(cur_node);
        
        for(int i = 0;i < connect_node[cur_node].size();i++){
            
            int next_node = connect_node[cur_node][i];
            
            // just judge the node is previous node or not, 
            // if so ,skip it to avoid infinite recursive
            if(abs(next_node) == prev_node)
                continue;
            
            // now we at cur_node, check this edge is cur_node to next_node,or next_node to cur_node
            // if it is "cur_node to next_node", this means we need to reverse it,
            // why reverse? because we start DFS from 0
            // "cur_node to next_node" means we go farer from 0
            if(connect_node[cur_node][i] > 0)
                tmp = tmp + 1 + dfs(connect_node, cur_node, next_node);
            else
                tmp = tmp + dfs(connect_node, cur_node, abs(next_node));
        }
        
        return tmp;
    }
};
