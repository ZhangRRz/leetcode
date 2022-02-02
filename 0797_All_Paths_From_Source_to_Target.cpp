class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> realans;
        
        //record temporary path the recursive had travel
        vector<int> temppath;
        
        findpath( 0, graph,realans,temppath);
        
        return realans;
    }
    
    // recursive call to DFS to find valid path
    void findpath(int nownode, vector<vector<int>>& graph, vector<vector<int>>& realans, vector<int>& temppath){
        temppath.push_back(nownode);
        
        //if reach goal
        if(nownode == graph.size()-1)
            realans.push_back(temppath);
        
        // if nownode can reach any node
        else
            //use for loop to recursive call all the node that nownodecan reach
            for(int i = 0; i < graph[nownode].size() ;i++)
                findpath( graph[nownode][i], graph,realans,temppath);
        
        
        temppath.pop_back();
    }
    
    
};
