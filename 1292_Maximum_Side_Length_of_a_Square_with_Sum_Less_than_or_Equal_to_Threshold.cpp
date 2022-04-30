/*
https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/discuss/451871/Java-sum%2Bbinary-O(m*n*log(min(mn)))-or-sum%2Bsliding-window-O(m*n)
*/

// re-implement as c++
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> sum(m+1 ,vector<int>(n+1, 0));
        
        int res = 0;
        int len = 1; // square side length

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
                
                if (i >= len && 
                    j >= len && 
                    sum[i][j] - sum[i-len][j] - sum[i][j-len] + sum[i-len][j-len] <= threshold)
                      
                    res = len++;
            }
        }
        return res;
    }
    
};
