/*
https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/833271/C%2B%2B-with-picture-O(n)
*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr){
        int sz = arr.size(), r = sz - 1;
        for (; r > 0 && arr[r - 1] <= arr[r]; --r);
        
        auto res = r;
        
        for (int l = 0; l < r && (l == 0 || arr[l - 1] <= arr[l]); ++l) {
            while (r < sz && arr[r] < arr[l])
                ++r;
            res = min(res, r - l - 1);
        }
        return res;
    }  
};
