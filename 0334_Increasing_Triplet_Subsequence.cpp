/*
 if the problem requires us to return the index, then this code would not work.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int i = INT_MAX;
        int j = INT_MAX;
        
        for(int k = 0;k < nums.size();k++){ 
            if(nums[k] < i) 
                i = nums[k];
            else if(nums[k] > i && nums[k] < j) 
                j = nums[k]; 
            else if(nums[k] > j) 
                return true; 
        }
        return false;
    }
};
