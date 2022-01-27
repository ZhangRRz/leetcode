class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int size1 = firstList.size();
        int size2 = secondList.size();
        
        vector<vector<int>> ans;
        if(size1 < 1 || size2 < 1 )
            return ans;
        
        int i1 = 0;
        int i2 = 0;
        while(i1 < size1 && i2 < size2){
            
             // means 2 interval have overlap
            if(firstList[i1][1] >= secondList[i2][0] && firstList[i1][0] <= secondList[i2][1]){

                // int interval_start = max(firstList[i1][0], secondList[i2][0]);
                // int interval_end = min(firstList[i1][1], secondList[i2][1]);
                // vector<int> v{interval_start,interval_end};
                
                // below line equals up three lines.
                vector<int> v{max(firstList[i1][0], secondList[i2][0]),min(firstList[i1][1], secondList[i2][1])};
                ans.push_back(v);
            }
            (firstList[i1][1] >= secondList[i2][1])? i2++ : i1++;
        }
        return ans;
    }
};
