class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int si = mat.size();
        if(si == 1)
            return mat[0][0];
        
        int sum = 0;
        for(int i = 0; i < si;i++){
            sum += (mat[i][i] + mat[i][si-1-i]);
        }
        
        if(si%2)
            return sum - mat[si/2][si/2];
        
        return sum;
    }
};
