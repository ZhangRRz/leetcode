/*
source:

https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

https://leetcode.com/problems/longest-increasing-subsequence/discuss/74848/9-lines-C%2B%2B-code-with-O(NlogN)-complexity

http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

[1,2,7,8,3,4,5,9,0]
1 -> [1]
2 -> [1,2]
7 -> [1,2,7]
8 -> [1,2,7,8]
3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence
4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence
5 -> [1,2,3,4,5]
9 -> [1,2,3,4,5,9]
0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence

*/


class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            
            if(it==res.end()) 
                res.push_back(nums[i]);
            else 
                *it = nums[i];
        }
        return res.size();
    }
};
