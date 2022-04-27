class Solution {
private:
    vector<int> tmp;
public:
    Solution(vector<int>& w) {
        tmp.push_back(w[0]);
        
        for(int i = 1;i < w.size();i++){
            tmp.push_back(tmp[i-1] + w[i]);
        }
    }
    
    int pickIndex() {
        int pick = rand()%tmp.back();
        auto it = upper_bound(tmp.begin(),tmp.end(),pick);
        
        return it - tmp.begin();
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
