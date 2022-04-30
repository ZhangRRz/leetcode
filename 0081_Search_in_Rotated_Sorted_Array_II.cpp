/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/180074/JAVA-0ms-solution-clear-and-simple
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
    
        while(i <= j) {

            int m = (i + j) / 2;
            if(nums[m] == target) return true;

            if(nums[m] == nums[i]) i++;   //"duplicate", jump

            // we are on the 'bigger' increasing side, like [5,5,7] from [5,5,7,0,1,3,4]
            else if(nums[m] > nums[i]) {

                // if target is between nums[i] and nums[m], it makes sense to set the right border to m-1
                if(nums[m] > target && nums[i] <= target) j = m - 1; 
                // if target is NOT between nums[i] and nums[m] 
                // then target is on the 'right' side of m ; limit the 'left' border [i=m+1]
                else i = m + 1;

            // case nums[m] < nums[i] : we are on the 'smaller' increasing side,
            // like [0,1,3,4] from [5,5,7,0,1,3,4] 
            } else {

                // if target is between nums[m] and nums[j], it makes sense to set the left border to m+1
                if(nums[m] < target && nums[j] >= target) i = m + 1;
                // if target is NOT between nums[m] and nums[j] 
                // then target is on the 'left' side of m ; limit the 'right' border [j=m-1]
                else j = m - 1;
            }
        }
        return false;
    }
    
};
