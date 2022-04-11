class Solution {
public:
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        
        //1. bulid a graph knowing what node connects to node i
        for(int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        //2. keep this vector and we will not visited a node again
        vector<bool> visited(n,false);
        
        // Bipartition one and two
        unordered_set<int> part1;
        unordered_set<int> part2;
        
        bool is_Bipartition = true;
        // 3. start DFS from node 1,because there's no node 0
        // look dfs function body below
        for(int i = 1; i < graph.size(); i++) {
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
        
        // remember every time, insert current node to "part1"
        part1.insert(i);
        
        // uncomment below part can know after every time doing dfs,what are in part1 and part2
        cout<<"set1------------  "<<endl;
        for(auto s:part1){
            cout<<s<<"  ";
        }
        cout<<endl<<"set2------------  "<<endl;
        for(auto q:part2){
            cout<<q<<"  ";
        }
        cout<<endl<<"===++++++++==="<<endl;

        int tmp = true;
        for(int k = 0;k < graph[i].size();k++){

            // once we find this node is in the same as current node
            // but it connects to current node, means Bipartition fail
            if(part1.count(graph[i][k]) == 1)
                return false;
            
            // careful , here pass the "part2 , part1" not "part1 , part2"
            // because we need insert node that connects to current node to "part2"
            tmp = tmp && dfs(graph[i][k], part2, part1, graph, visited);
        }
        
        return tmp;
    }
};
