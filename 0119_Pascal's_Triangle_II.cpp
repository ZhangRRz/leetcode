class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        if(rowIndex == 0)
            return ans;
        
        ans.push_back(rowIndex);
                
        int cur = 2;
        
        // Pascal's Triangle can be repersent as nCm which n = rowIndex ,m = elementIndex
        for(;cur < (rowIndex+1+1)/2;cur++){
            
            int time = 0;
            double ele = 1;
            while(time < cur){
                ele = ele*(rowIndex-time)/(time+1);
                time++;
            }
            
            ans.push_back(ele);
            
        }
            
        
        // Pascal's Triangle element at index 0 ~ (n+1)/2 is the same as n ~ (n+1)/2
        for(;cur < rowIndex+1;cur++)
            ans.push_back(ans[rowIndex-cur]);
        
        return ans;
    }
};
