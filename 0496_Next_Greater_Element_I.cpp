/*
idea:
https://leetcode.com/problems/next-greater-element-i/discuss/97595/Java-10-lines-linear-time-complexity-O(n)-with-explanation
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> map;
        stack<int> s;
        vector<int> ans;
        
        for(int i = 0;i < nums.size();i++) {
            
            while (s.size() && s.top() < nums[i]) {
                map[s.top()] = nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }
        
        
        for(int i = 0;i < findNums.size();i++){
            
            auto it = map.find(findNums[i]);
            if(it == map.end())
                ans.push_back(-1);
            else
                ans.push_back(it -> second);
                
        }
        
        return ans;
    }
};
