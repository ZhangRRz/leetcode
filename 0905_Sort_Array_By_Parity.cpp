class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i = 0;
        int j = nums.size()-1;
        
        while(i < j){       
            
            if(nums[i]%2){
                while(i < j && nums[j]%2)
                    j--;
                swap(nums[i],nums[j]);
            }
            i++;
        }
        
        return nums;
    }
};
