class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> able(n,0);
        vector<int> ans;
        for(vector<int> i:edges){
            able[i[1]] = 1;
        }
        for(int i = 0; i < able.size();i++){
            if(!able[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};
