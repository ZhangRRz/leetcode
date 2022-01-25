class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int down_limit_lenght = 0;
        int up_limit_lenght = nums.size()-1;
        int now_middle_ele = 0;
        vector<int> result{-1,-1};
        
        if( nums.size() > 2){
            //because list is sorted
            while(true){//use binary search to determinate upper index and lower index
                now_middle_ele = nums[(up_limit_lenght+down_limit_lenght)/2];

                if(now_middle_ele < target){
                    down_limit_lenght = ((up_limit_lenght+down_limit_lenght)/2);
                }
                else if(now_middle_ele > target){
                    up_limit_lenght = ((up_limit_lenght+down_limit_lenght)/2);
                }
                else{//if the middle of list is just what we wanna find, dont cut the list in half again
                    break;
                }
                if(up_limit_lenght <= down_limit_lenght+1){
                    break;
                }
            }    
        }else{//list len < 2
            down_limit_lenght = 0;
            up_limit_lenght = nums.size()-1;
        }
        
        // start to find list in the index range we pick
        int findfirst_flag = 0;
        for(int i = down_limit_lenght; i <= up_limit_lenght;i++ ){
            if(nums[i] == target and !findfirst_flag){
                result[0] = i;
                findfirst_flag = 1;
            }
            if(nums[i] == target and findfirst_flag){
                result[1] = i;
            }
            
        }
        return result;
    }
};
