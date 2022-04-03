class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int max_dis = m+n;
        
        /*
        first for traval from mat[0][0] to mat[n-1][m-1]
        ignore 0 
        if != 0, compare above and left element
        then assign min(top,left)+1 to current element;
        */
        for(int i = 0;i < mat.size();i++){
            for(int j = 0;j < mat[0].size();j++){
                
                if(mat[i][j] != 0){
                    
                    int top = max_dis,left = max_dis;
                    if(j != 0)
                        left = mat[i][j-1];
                    if(i != 0)
                        top = mat[i-1][j];
                    
                    mat[i][j] = min(top,left)+1;
                }
                
            }
        }
        /*
        first for traval from mat[n-1][m-1] to mat[0][0]
        ignore 0 
        if != 0, compare below and right element
        then assign min(mat[i][j], min(buttom,right)+1) to current element;
        */
        for(int i = n-1;i >= 0;i--){
            for(int j = m-1;j >= 0;j--){
                
                if(mat[i][j] != 0){
                    
                    int buttom = max_dis,right = max_dis;
                    if(j != m-1)
                        right = mat[i][j+1];
                    if(i != n-1)
                        buttom = mat[i+1][j];
                    
                    mat[i][j] = min(mat[i][j], min(buttom,right)+1);
                }
            }
        }
        
        return mat;
        
    }
};
