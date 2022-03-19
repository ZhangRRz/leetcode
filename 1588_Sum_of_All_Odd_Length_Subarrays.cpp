/*

idea:
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/discuss/854304/C%2B%2B-O(N)-Single-Line-Logic
*/


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0, si = arr.size();
        for (int i = 0; i < si; ++i) {
            ans += ((i + 1) * (si - i) + 1) / 2 * arr[i];
        }
        return ans;
    }
};
