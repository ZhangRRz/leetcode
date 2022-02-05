class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size() == 1)
            return 0;
        
        int step_count = 0,cur_index = 0;
        
        while(cur_index+nums[cur_index] < nums.size()-1){
            
            step_count++;
            int start = cur_index+1;
            int end = cur_index+nums[cur_index]+1;
            
            for(int i = start; i < end; i++){
                
                if(cur_index + nums[cur_index] < i + nums[i]){
                    cur_index = i;
                    if(i + nums[i] >= nums.size()-1)
                        break;
                }
                
            }
            
        }
        return step_count+1;
        
    }
};
