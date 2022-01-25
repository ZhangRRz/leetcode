#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>::iterator ptr;
        map<int,int> numlist;
        vector<int> ans;
        
        for(int i = 0;i < nums.size();i++){
            
            ptr = numlist.find(target-nums[i]);
            if(ptr != numlist.end()){
                ans.push_back(ptr->second);
                ans.push_back(i);
                return ans;
            }

            numlist[nums[i]] = i;
          
        }
        return ans;
    }
};
