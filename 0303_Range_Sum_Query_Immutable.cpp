class NumArray {
public:
    NumArray(vector<int>& nums) {
        
        arr.push_back(0);
        for (int i = 0;i < nums.size();i++)
            arr.push_back(arr.back() + nums[i]);
    }
    
    int sumRange(int left, int right) {
        
        return arr[right + 1] - arr[left];
    }
private:
    vector<int> arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
