/*
https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175090/JavaC%2B%2BPython-Sliding-Window
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        uint l = 0, r = 1, incrementsRequired = 0;
        
        for(; r < size(nums); r++){            
            // increments requried to bring all nums[j] (for l <= j < r) to nums[r]
            incrementsRequired += (nums[r] - nums[r - 1]) * (r - l);
            // if increment required become greater than k, then, 
            // reduce the increments required to get nums[l] to nums[r] & slide left pointer forward
            if(incrementsRequired > k)
                incrementsRequired -= (nums[r] - nums[l++]);              
        }
        // finally the [l, r] window 
        // will hold the size of maximum number of elements that can be made equal
        return r - l;
    }
};
