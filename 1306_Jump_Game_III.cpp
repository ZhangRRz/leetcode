class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(),false);
        
        return dfs(arr, visited, start);
    }
    
    bool dfs(vector<int>& arr, vector<bool>& visited, int cur){
        bool ans = false;
        visited[cur] = true;
        if(arr[cur] == 0)
            return true;
        
        int next = cur - arr[cur];
        if(next >= 0 && !visited[next])
            ans = ans || dfs(arr, visited, next);
        
        next = cur + arr[cur];
        if(next < arr.size() && !visited[next])
            ans = ans || dfs(arr, visited, next);
        
        return ans;
        
    }
};
