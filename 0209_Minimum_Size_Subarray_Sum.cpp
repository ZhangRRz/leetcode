class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        if(!nums.size())
            return 0;
        
        int window_start = 0;
        int sum = 0;  
        int window_end = 0;
        
        // find first window that sum >=  target
        while(window_end < nums.size()){
            sum += nums[window_end];
            if(sum >= target)
                break;
            window_end++;
        }
        
        if(sum < target)
            return 0;
        // adjust the window to fit size
        while(sum > target && window_start <= window_end){
            if(sum - nums[window_start] < target)
                break;
            sum -= nums[window_start];
            window_start++;
        }
        
        // use the size we decide to slide over the rest of list
        // if find smaller window size ,just the same thing to adjust window to fit size
        for(window_end++; window_end < nums.size();window_end++){
            
            window_start++;
            sum  = sum + nums[window_end] - nums[window_start-1];
            
            // if find smaller window size
            while(sum > target && window_start <= window_end){
                if(sum - nums[window_start] < target)
                    break;
                sum -= nums[window_start];
                window_start++;
            }
        
        }
       
        //because window_end < nums.size() in previous for will make
        // window_end == nums.size() when for loop jump out, so (window_end-1) is correct 
        return (window_end-1) - window_start+1;
        
    }
};
