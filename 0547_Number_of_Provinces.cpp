class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
        if(isConnected.size() == 1)
            return 1;
        
        // to record if the number visited before
        // avoid recursive call
        vector<int> visited(isConnected.size(),0);
        int ans = 0;
        
        for(int i = 0;i < isConnected.size();i++ ){
            for(int j = i ;j < isConnected[i].size();j++){
                //find new group
                if(!visited[j] && isConnected[i][j] == 1){
                    ans++;
                    prcoess_Connected_map(j, visited,isConnected);
                }    
            }
        }
        
        return ans;
    }
    void prcoess_Connected_map(int j ,vector<int>& visited, vector<vector<int>>& isConnected){
        visited[j] = 1;
        
        // find all the nums satisfied 
        // (1) not be visited  (2) connect == 1;
        // once find recursive call
        for(int k = 0;k < isConnected[j].size();k++){
            if(!visited[k] && isConnected[j][k] == 1){
                prcoess_Connected_map(k, visited,isConnected);
            }
        }
    }
    
};
