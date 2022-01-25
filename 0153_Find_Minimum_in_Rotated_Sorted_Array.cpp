class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        int ans = 0;
        while(left <= right)
        {
            mid = (left + right)/2;
            
            // if mid is greater than end 
            // means min is at left of mid
            
            // if mid is not greater than end 
            // means min is at right of mid
            if(nums[mid] > nums.back())
                left = mid + 1;
            else{// save only when min is at right of mid
                ans = mid;
                right = mid - 1;
            }
        }
        return nums[ans];
    }
    // function call lazy soiution
    //     // sort(nums.begin(), nums.end());
    //     // return nums[0];
    // }
};
