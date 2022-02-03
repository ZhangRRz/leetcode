/*
if nums = [1,3,3,3,3,4];
first put []  now ans =[[]] 

next loop put 1 to every element of ans so ans == [[],[1]]  ,duplicate_start = ans.size()/2 = 1

next loop put 3 to every element of ans so ans == [[],[1],[3],[1,3]] ,duplicate_start = ans.size()/4 = 2

first time of duplicate
next loop is 3 ,duplicate as previous element ,so we only allow this 3 to put in to 
    "half of elments to end of elments"  of ans ,this means star from duplicate_start( = 2)
    so this 3 put into ans[2] and ans[3]
    then ans == [[],[1],[3],[1,3],[2,3],[1,2,3]]
    
second time of duplicate
next loop is 3 ,duplicate as previous element again ,so we only allow this 3 to put in to 
    ( the place that previous 3 was allowed ) + ( duplicate_start )= "2" + 2 = 4
    so this 3 put into ans[4] to ans[5]

 
third time of duplicate
next loop is 3 ,duplicate as previous element again ,so we only allow this 3 to put in to 
    ( the place that previous 3 was allowed ) + ( duplicate_start )= "4" + 2 = 6
    so this 3 put into ans[6] to ans[7]

next loop = 4 ,no duplicate ,set duplicate_start = ans.size()/2;
    then put 4 into every element of ans
 
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{{}};
        
        int duplicate_start = 0;
        int start = 0;
        for(int i = 0;i < nums.size();i++){
            int asize = ans.size();
            
            
            if(i-1 > -1 && nums[i] == nums[i-1])
                start += duplicate_start;
            else
                start = 0;
            
            
            for(int j = start;j < asize;j++){
                
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
                
            }
            
            // if 0 or nums[i] != nums[i-1] means next loop we can put nums[i] into every ans[j];
            if ((i==0)||(i-1 > -1 && nums[i] != nums[i-1]))
                duplicate_start = ans.size()/2;
        }
        
        return ans;
    }
    
};
