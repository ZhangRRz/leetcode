class Solution {
public:
    double average(vector<int>& salary) {
        
        int lo = INT_MAX;
        int hi = INT_MIN;
        int sum = 0;
        for(int i:salary){
            lo = min(lo,i);
            hi = max(hi,i);
            sum += i;
            
        }
        return (sum-lo-hi)/1.0/(salary.size()-2);
    }
    
};
