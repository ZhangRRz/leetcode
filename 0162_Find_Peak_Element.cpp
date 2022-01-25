class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = (left + right)/2;
        
        while (left <= right){
            mid = (left + right)/2;
            
            //if right and left close enough
            if(right - left <=1)
                return (nums[left] > nums[right]? left : right);
            //if mid = 0
            if(mid == 0) return mid;
            
            //accroding to left element to know slope is passtive or negtive
            //peak is at left of mid
            if(nums[mid] < nums[mid-1]){
                right = mid;
            }
            else  //peak is at right of mid
                left = mid;
        }
        
        
        return mid;
    }
};
