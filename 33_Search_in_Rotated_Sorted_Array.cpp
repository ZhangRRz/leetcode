class Solution {
public:
    int search(vector<int>& nums, int target){
        
        int lower = 0;   
        int upper = nums.size()-1;
        int mid = 0;
        while(lower <= upper){
            mid = (lower + upper) / 2;
            if(target == nums[mid])
                return mid;

            // key point is check which side is sorted, then check target is 
            if(nums[lower] <= nums[mid]){ // left is sorted
                if(target <= nums[mid] && target >= nums[lower]) // check target is in this side
                    upper = mid - 1;
                else
                    lower = mid + 1;
            }

            else{ // right is sorted 
                if(target >= nums[mid] && target <= nums[upper]) // check target is in this side
                    lower = mid + 1;
                else
                    upper = mid - 1;
            }
        }
        return -1;
   }
};
