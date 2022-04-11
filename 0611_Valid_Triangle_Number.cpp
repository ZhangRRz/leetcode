/*
idea 
https://leetcode.com/problems/valid-triangle-number/discuss/1339340/C%2B%2BJavaPython-Two-Pointers-Picture-Explain-Clean-and-Concise-O(N2)

*/
class Solution {
public:
    int triangleNumber(vector<int>& nums){
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = 0;
        for(int k = 2; k < n; ++k) {
            int i = 0;
            int j = k - 1;
            
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    ans += j - i;
                    j--;
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};
