class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {    
        vector<int> Safe_States_list;
        vector<int> visited;

        for(int i = 0;i < graph.size();i++){
            
            if(graph[i].size() == 0 || graph[i][0] == -2){
                Safe_States_list.push_back(i);
            }else if(graph[i][0] != -1){

                // mark as safe;
                if(dfs_judge(i, graph, visited))
                    Safe_States_list.push_back(i);
            }
        }
        
        return Safe_States_list;
    }
    
    bool dfs_judge(int i, vector<vector<int>>& graph, vector<int>& visited){

        if(find(visited.begin(), visited.end(), i) != visited.end()){
            graph[i][0] = -1;
            return false;
        }
        else if(graph[i].size() == 0 || graph[i][0] == -2)
            return true;
        else if(graph[i][0] == -1)
            return false;
        else{
            visited.push_back(i);
            
            for(int j = 0;j < graph[i].size();j++){
                if(dfs_judge(graph[i][j], graph, visited) == false){
                    // mark as unsafe;
                    graph[i][0] = -1;
                    visited.pop_back();
                    return false;
                }
            }
        }
        
        visited.pop_back();
        // mark as safe;
        graph[i][0] = -2;
        return true;
    }
     
};
