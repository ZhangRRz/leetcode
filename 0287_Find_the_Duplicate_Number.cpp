/*
binary search approach explanation
https://leetcode.com/problems/find-the-duplicate-number/discuss/1892921/Java-9-Approaches-Count-%2B-Hash-%2B-Sort-%2B-Binary-Search-%2B-Bit-%2B-Fast-Slow-Pointers
*/

class Solution {
public:
    
    // binary search approach
    int findDuplicate(vector<int>& nums) {

        int low = 1;
        int high = nums.size() - 1;
        
        while (low < high) {
            
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid)
                    cnt++;  
            }

            if (cnt <= mid)
                low = mid + 1;
            else 
                high = mid;
            
        }

        return low;

    }
    
//     // using negtive value to fasten
//     int findDuplicate(vector<int>& nums) {
        
//         int ans = -1;   
//         for (int i = 0; i < nums.size(); i++) {
//             int val = abs(nums[i]);
//             if (nums[val] < 0) {
//                 ans = val;
//                 break;
//             }
//             nums[val] = -nums[val];
//         }

//         return ans;
//     }
    
    
    
};
