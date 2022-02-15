class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count = 0;
        int index = 0;
        while(count < nums.size()){
            
            // if == 0 erase and insert 0 at begin
            if(nums[index] == 0){
                nums.erase(nums.begin() + index);
                nums.insert(nums.begin() , 0);
                index++;
                
                
            }
            // if == 2 erase and push_back 2
            else if (nums[index] == 2){
                nums.erase(nums.begin() + index);
                nums.push_back(2);
            }
            // if == 1 just skip
            else{
                index++;
            }
            
            
            count ++;
        }
    }
};
