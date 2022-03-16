class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0,to_swap = 0;
        
        while(i < nums.size()){
           
           if(nums[i] != 0){
               swap(nums[to_swap],nums[i]);
               to_swap++;
           }
           
            i++;
        }     
    }
};
