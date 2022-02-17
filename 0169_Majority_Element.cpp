/*

Boyer-Moore Majority Vote Algorithm
http://www.cs.utexas.edu/~moore/best-ideas/mjrty/

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int major;
        int count = 0;
        
        for(int i = 0 ;i < nums.size(); i++){
            
            if(count == 0){
                major = nums[i];
                count++;
            }
            else if(major == nums[i])
                count++;
            else
                count--;
        }
        
        return major;
    }
};
