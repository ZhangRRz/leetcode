/*
do binary search from 1 to max element of piles
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, r = *max_element(piles.begin(), piles.end());
        
        while (l < r) {
            int mid = (l+r)/2;
            int total_time = 0;
            
            for (int i = 0;i < piles.size();i++)
                total_time += (piles[i] + mid-1) / mid;
            
            if (total_time > h)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

};
