/*
idea
https://leetcode.com/problems/subarray-sum-equals-k/discuss/1532102/JAVA-oror-Picture-%2B-Detail-Explanation-oror-2-methods-oror-prefix-sum-%2B-HashMap-oror-Easy-Solution

*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> sum_map;
        int sum = 0,ans = 0;
        
        sum_map[sum] = 1;
        
        for(int element:nums){
            sum += element;
            
            if(sum_map.find(sum - k) != sum_map.end())
                ans += sum_map[sum - k];
            
            sum_map[sum]++;
        }
        return ans;
    }
};
