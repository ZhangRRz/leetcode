/*
https://leetcode.com/problems/minimum-absolute-sum-difference/discuss/1141339/C%2B%2B-O(n-log-n)
*/
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        long res = 0, gain = 0;
        set<int> s(begin(nums1), end(nums1));
        
        for (int i = 0; i < nums1.size(); ++i) {
            long original = abs(nums1[i] - nums2[i]);
            res += original;

            if (gain < original) {
                auto it = s.lower_bound(nums2[i]);
                if (it != end(s))
                    gain = max(gain, original - abs(*it - nums2[i]));
                
                if (it != begin(s))
                    gain = max(gain, original - abs(*prev(it) - nums2[i]));
            }
        }
        return (res - gain) % 1000000007;
    }
};
