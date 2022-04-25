class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), left = 1, right = 1e9;
        
        if (m * k > n) 
            return -1;
        // mid is minimum number of days
        while (left < right) {
            int mid = left + (right - left) / 2;
            int flowers = 0;
            int bouquets = 0;
            for (int i = 0; i < n; i++) {
                if(bloomDay[i] <= mid){
                    flowers++;
                    // make a Bouquets
                    if (flowers >= k){
                        bouquets++;
                        flowers = 0;
                    }
                }
                // not enough k adjacent flowers 
                else{
                    flowers = 0;
                }
            }
            
            if(bouquets < m)
                left = mid + 1;
            else 
                right = mid;
            
        }
        return left;
    }
};
