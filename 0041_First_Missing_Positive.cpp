/*
if nums.size() = n
means : 0 < First Missing Positive <= n + 1
so in vector, if nums[i] not satisfies  0 < nums[i] <= n , means it is a useless data.
if nums[i] satisfies ,then we swap it to a correct place ,
    for example: if nums.size() = 10 and 
    num[i] == 1
    then we swap it to num[num[i]-1] ,meas swap to num[0]
    
    num[i] == 8
    then we swap it to num[7]

after above process, we traversal vector again,
now we know if num[i] != i+1, means this Positive Number is Missing
just return i+1.

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n;){
            if(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1] , nums[i]);
            else
                i++;
        }
        
        for (int i = 0; i < n; i++){
            if (nums[i] != i+1 ) 
                return i+1;
        }
        
        return n + 1;
    }
};
