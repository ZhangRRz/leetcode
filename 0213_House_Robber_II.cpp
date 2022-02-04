/*
source
https://leetcode.com/problems/house-robber-ii/discuss/59921/9-lines-0ms-O(1)-Space-C%2B%2B-solution

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        
        if (n < 2) 
            return n ? nums[0] : 0;
        
        // reduse to 2 House Robber problem
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }

    
    int robber(vector<int>& nums, int l, int r) {
        
        
        int previous_house = 0, current_house = 0;
        for (int i = l; i <= r; i++) {
            int current_best = max(previous_house + nums[i], current_house);
            previous_house = current_house;
            current_house = current_best;
        }
        return current_house;
    }
};
