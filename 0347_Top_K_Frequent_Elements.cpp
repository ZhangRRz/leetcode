class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        unordered_map<int, int> freq;
        
        // build map <number , frequency of number>
        for (int i = 0 ;i < nums.size(); i++) 
            freq[nums[i]]++;
        
        for (auto p : freq) {
            min_heap.push({p.second, p.first});
            
            if(min_heap.size() > k) 
                min_heap.pop();
        }
        
        // after above loop , heap store Top K Frequent Elements
        vector<int> ans;
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};
