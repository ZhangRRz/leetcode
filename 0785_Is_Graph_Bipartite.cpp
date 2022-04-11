/*
totally the same as 886. Possible Bipartition
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<bool> visited(graph.size(),false);

        unordered_set<int> part1;
        unordered_set<int> part2;
        
        bool is_Bipartition = true;

        
        for(int i = 0; i < graph.size(); i++) {
            is_Bipartition = is_Bipartition && dfs(i,part1,part2,graph,visited);
        }
        
        return is_Bipartition;
    }
    
    bool dfs(int i, unordered_set<int>& part1, unordered_set<int>& part2,
            vector<vector<int>>& graph, vector<bool>& visited){
        

        if(!visited[i])
            visited[i] = true;
        else
            return true;
        
        part1.insert(i);

        int tmp = true;
        for(int k = 0;k < graph[i].size();k++){

            if(part1.count(graph[i][k]) == 1)
                return false;

            tmp = tmp && dfs(graph[i][k], part2, part1, graph, visited);
        }
        
        return tmp;
    }
};
