class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int left = 1, right = *max_element(nums.begin(), nums.end())+1;
        int mid = 0;
        int sum_of_threshold = 0;
        while (left < right) {
            mid = left + (right - left ) / 2;
            sum_of_threshold = 0;
            
            // because question requires
            // "rounded to the nearest integer greater than or equal to that element"
            for (int i = 0;i < nums.size();i++)
                sum_of_threshold += (nums[i] + mid - 1) / mid;
            
            if (sum_of_threshold > threshold)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
