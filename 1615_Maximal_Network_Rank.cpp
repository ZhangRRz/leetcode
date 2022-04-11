class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);

         for(int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
        }
        
        int max_rank = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
               
                int tmp_rank = graph[i].size() + graph[j].size();

                if (graph[j].count(i))
                    tmp_rank--;

                max_rank = max(max_rank, tmp_rank);
            }
            
        }
        return max_rank;
    }
};
