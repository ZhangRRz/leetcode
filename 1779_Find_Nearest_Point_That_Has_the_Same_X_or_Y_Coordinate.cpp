class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        
        int min_MD = INT_MAX;
        int index = -1;
        for(int i = 0;i < points.size();i++){
            
            if(x == points[i][0]){
                
                int dis = abs(y - points[i][1]);
                if(min_MD > dis){
                    index = i;
                    min_MD = dis;
                }
            }
            else if(y == points[i][1]){
                
                int dis = abs(x - points[i][0]);
                if(min_MD > dis){
                    index = i;
                    min_MD = dis;
                }
            }
            
        }
        return index;
    }
};
