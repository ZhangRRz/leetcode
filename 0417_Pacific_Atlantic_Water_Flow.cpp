/*
idea:
https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1126938/Short-and-Easy-w-Explanation-and-diagrams-or-Simple-Graph-traversals-DFS-and-BFS
*/
class Solution {
public:
    int m, n;
	
    vector<vector<bool> > to_atlantic, to_pacific;
    vector<vector<int> > ans;    
    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
        
        if(!mat.size()) 
            return ans;
        m = mat.size(), n = mat[0].size();
        to_atlantic = to_pacific = vector<vector<bool> >(m, vector<bool>(n, false));
        
		//  dfs all edge cells
        for(int i = 0; i < m; i++){
            dfs(mat, to_pacific, i, 0);
            dfs(mat, to_atlantic, i, n - 1);
        }
            
        for(int i = 0; i < n; i++) {
            dfs(mat, to_pacific, 0, i);
            dfs(mat, to_atlantic, m - 1, i); 
        }
        return ans;
    }
    
    // use visited to mark visited and represent visited[i][j] can flow to atlantic or pacific
    void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
        if(visited[i][j]) 
            return;
        
        visited[i][j] = true;
        
        if(to_atlantic[i][j] && to_pacific[i][j]) 
            ans.push_back(vector<int>{i, j});
        
		// if next is greater ,means water can flow from next to current
        if(i + 1 <  m && mat[i+1][j] >= mat[i][j]) 
            dfs(mat, visited, i+1, j); 
        
        if(i - 1 >= 0 && mat[i-1][j] >= mat[i][j]) 
            dfs(mat, visited, i-1, j);
        
        if(j + 1 <  n && mat[i][j+1] >= mat[i][j]) 
            dfs(mat, visited, i, j+1); 
        
        if(j - 1 >= 0 && mat[i][j-1] >= mat[i][j]) 
            dfs(mat, visited, i, j-1);
    }
};
