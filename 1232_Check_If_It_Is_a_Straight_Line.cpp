class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int x1 = coordinates[0][0] - coordinates[1][0];
        int y1 = coordinates[0][1] - coordinates[1][1];
        
        for(int i = 1;i < coordinates.size() - 1;i++){

            int x2 = coordinates[i][0] - coordinates[i+1][0];
            int y2 = coordinates[i][1] - coordinates[i+1][1];
            
            if(x1*y2 != x2*y1){
                return false;
            }            
        }
        return true;
    }
};
