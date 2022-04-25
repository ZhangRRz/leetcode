class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int left = 0,right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(mid+1 < nums.size() && nums[mid] == nums[mid+1]){
                if(mid%2 == 0)
                    left = mid + 1;
                else
                    right = mid;
            }else if(mid-1 >= 0 && nums[mid] == nums[mid-1]){
                if(mid%2 == 0)
                    right = mid;
                else
                    left = mid + 1;
            }else
                return nums[mid];
                
        }
        
        return nums[right];
    }
};
