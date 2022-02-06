class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size() < 3)
            return 0;
        
        int ans = 0;
        int count = 0;
        
        //
        // if we have [1,2,3] then ans = 1
        // if we have [1,2,3,4] then ans = 3
        // if we have [1,2,3,4,5] then ans = 6
        // if we have [1,2,3,4,5,6] then ans = 10
        // can see the length of Arithmetic Slices is n
        // ans is 1+2+3...+n
        // count += 1 then ans += count can acheive is sum;
        // if we detect not Arithmetic Slices ,just make count = 0
        // 
        for(int i = 1; i < nums.size()-1 ;i++){
            if(nums[i-1] + nums[i+1] == 2*nums[i])
                count += 1;
            else
                count = 0;
            
            ans += count;
        }
        
        return ans;
    }
};
