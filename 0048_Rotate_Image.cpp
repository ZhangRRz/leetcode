/*
source:
https://leetcode.com/problems/rotate-image/discuss/19123/6-lines-of-code-and-with-O(1)-space-in-c%2B%2B

*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }

};
