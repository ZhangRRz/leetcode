class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,int> anagrams_and_index_of_ans;
        vector<vector<string>> ans;
        
        for(string s:strs){
            string tmp = s;
            // sort s as the key of map
            sort(s.begin(),s.end());
            
            if(anagrams_and_index_of_ans.find(s) != anagrams_and_index_of_ans.end())
                ans[anagrams_and_index_of_ans[s]].push_back(tmp);
            else{
                anagrams_and_index_of_ans[s] = ans.size();
                ans.push_back({tmp});
            }
        }
        
        return ans;
    }
};
