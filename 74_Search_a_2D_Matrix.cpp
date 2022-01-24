class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        int mid =0;
        
        //just do binary search 2 times
        while(true){
            if(abs(left-right) <= 1)
                break;
            mid = (left + right)/2;
            
            if(matrix[mid][0] > target ){
                right = mid - 1;
            }else{
                left = mid;
            }
        }
        int pinned_inner_vector = 0;
        if(matrix[right][0] > target )
            pinned_inner_vector = left;
        else
            pinned_inner_vector = right;

        left = 0;
        right = matrix[pinned_inner_vector].size()-1;
        
        while(left <= right){
            mid = (left + right)/2;
            if(matrix[pinned_inner_vector][mid] == target)
                return true;
            
            if(matrix[pinned_inner_vector][mid] > target ){
                right = mid - 1;
            }else
                left = mid + 1;
        }
            
        return false;
    }
};
