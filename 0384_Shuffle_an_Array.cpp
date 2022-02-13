class Solution {
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> shuffle_vec = origin;
        
        for (int i = origin.size() - 1; i >= 0; i--) {
            
            // use rand to generate random index to swap
            swap(shuffle_vec[i], shuffle_vec[rand() % (i+1)]);
        }
        
        return shuffle_vec;
    }
    
private:    
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
