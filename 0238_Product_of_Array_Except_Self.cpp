/*
https://leetcode.com/problems/product-of-array-except-self/discuss/1597994/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Prefix-and-Suffix-product-O(1)-space-approach

*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        for(int i = 0, suf = 1, pre = 1, n = size(nums); i < n; i++) {
            
             // prefix product being calculated
            ans[i] *= pre;            
            pre *= nums[i];			
            // suffix product being calculated
            ans[n-1-i] *= suf;         
            suf *= nums[n-1-i];
        }
        return ans;
    }
};
