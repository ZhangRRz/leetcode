class Solution {
public:
    string frequencySort(string s) {

        priority_queue<pair<int, int>> max_heap;
        unordered_map<char, int> freq;
        
        
        // build map <number , frequency of number>
        for (int i = 0 ;i < s.size(); i++) 
            freq[s[i]]++;

        for (auto p : freq) 
            max_heap.push({p.second, p.first});
        

        // max_heap.top().first is frequency
        // max_heap.top().second is the letter
        string ans = "";
        while (!max_heap.empty()) {
            
            for (int i = max_heap.top().first ;i > 0; i--){
                ans += max_heap.top().second;
            }
            
            max_heap.pop();
        }
        return ans;
    }
};
