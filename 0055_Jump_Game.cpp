/*
what I write is not a DP solution

*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        for(int i = 0; i < nums.size();){
            
            if(i+nums[i] >= nums.size()-1)
                return true;
            
            if(nums[i] == 0)
                return false;
            
            int target = i+nums[i];
            
            // if do max jump >> nums[i+nums[i]] == 0;
            if(nums[target] == 0){
                int j;
                for(j = target-1 ;j > -1 ;j--){
                    
                    // if we jump into 0
                    // and got elements before 0 like 5,4,3,2,1,0
                    // we can know if elements - 0  is not greater than distence of index of 2 element
                    // means it still can not escape from jumping into 0
                    // example :  0 have index i ,so 2 have index i-2 but  2-0 is not greater than i-(i-2)
                    if(nums[j]-nums[target] > target - j){
                        i = j;
                        break;
                    }
                }
                // if for loop over means can not find middle point to jump;
                // at that time j == -1
                if(j == -1)
                    return false;
            }
                
            else
                i = target;
        }
            
        return true;
        
//         /*
//         below is another solution
//         https://leetcode.com/problems/jump-game/discuss/20907/1-6-lines-O(n)-time-O(1)-space
//         */
//         int goal=nums.size()-1, i;
        
//         for (i=nums.size()-1; i--;)
//             if (i+nums[i] >= goal)
//                 goal=i;
        
//         return !goal;
    }
    
};
