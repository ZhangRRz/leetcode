class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> pair;
        int ans = 0;
        
        for(int i: nums)
            if(pair[k-i]){
                pair[k-i]--;
                ans++;
            }
            else 
                pair[i]++;
        
        return ans;
    }
};

// faster Solution

// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int ans=0,i=0,j=nums.size()-1;
//         while(i<j){
//             if(nums[i]+nums[j]==k){
//                 ans++,i++,j--;
//             }
//             else if(nums[i]+nums[j]>k){
//                 j--;
//             }else{
//                 i++;
//             }
//         }
//         return ans;
//     }
// };
