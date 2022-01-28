class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(!k || !nums.size())
            return 0;
        
        int window_len = 0;
        
        int product = 1;
        int ans = 0;
        for(int window_end = 0;window_end < nums.size();window_end++){
            
            product *= nums[window_end];
            window_len++;
            
            // product >= k means need to make window smaller
            if(product >= k){
                while(product >= k && window_len > 0){
                    product /= nums[window_end-window_len+1];
                    window_len--;
                }
            }
            ans += window_len;
        }
        return ans;
        
    }
};
