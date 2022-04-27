/*
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/730511/C%2B%2B-priority_queue-solution
*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
        for (int i=0; i<n; i++)
            // pair.first means current value
            // pair.second means next index in nums that need to be add into pair.first
            mqueue.push({nums[i], i+1});

        int ans = 0, mod = 1e9+7;
        for (int i = 1; i <= right; i++) {
            auto p = mqueue.top();
            mqueue.pop();
            if (i >= left)
                ans = (ans + p.first) % mod;
            if (p.second < n) {
                // we already process the p.first which is smallest value in current mqueue
                // p.first can add a next number in nums to make it greater
                // and the nums[p.second] is the next number p.first should add
                // then p.second++ to indicate next index of number that new p.first should add
                // final, push p into mqueue
                //----------------------------
                // detail example
                // nums = [1,5,7,9]
                // we can see all sub array sum are
                // 1,  1+5,  1+5+7, 1+5+7+9
                // 5,  5+7,  5+7+9
                // 7,  7+9
                // 9
                // after first for loop we mqueue.push();
                // mqueue belike : 1, 5, 7, 9
                // after first time we mqueue.pop();
                // p.first = 1 and p.second = 2;
                // this means after process p 
                // p needs to add next number to generate next sub array sum
                // what number should "sub array sum 1" add?  it is 5
                // why is 5? because all sub array sum that include 1 are 1, 1+5, 1+5+7, 1+5+7+9
                // so p.first += nums[p.second] do the job
                // now we have to second++ 
                // to indicate next index of number that "sub array sum 1+5" should add
                // finally , we produce a new p and push into mqueue
                
                p.first += nums[p.second++];
                mqueue.push(p);
            }
        }
        return ans;
    }
};
