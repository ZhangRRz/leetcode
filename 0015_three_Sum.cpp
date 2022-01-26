class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //we can choose any target ,this time target = 0
        int target = 0;
        
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        //sort array first
        sort(nums.begin(), nums.end());
        for(int x = 0;x < nums.size()-2;x++){
            
            // X+Y+Z ,we determint X first than call two sum to slove Y+Z
            // so we skip duplicate X
            if(x != 0 && nums[x] == nums[x-1])
                continue;
            
            //deteminat X  calc Y+Z;
            int y = x+1;
            int z = nums.size()-1;
            
            while(y < z){
                int sum = nums[x] + nums[y] + nums[z];
                // match from nums[y] to nums[z-1])
                if(sum == target){
                    vector<int> find_one{nums[x], nums[y] , nums[z]};
                    ans.push_back(find_one);
                    //skip the same y
                    while( nums[x] + nums[y] + nums[z] == target && y < z)
                        y++;
                }else{// if still not find match for Y+Z.
                    if(sum < target)
                        y++;
                    else //(sum > target)
                        z--;
                }     
            }
        }
        return ans;
    }
};
