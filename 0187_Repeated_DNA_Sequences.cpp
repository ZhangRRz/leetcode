class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string pattern = s.substr(0,10);
        
        unordered_map<string,int> repeated_ans;
        repeated_ans[pattern] = 1;
        
        vector<string> ans;
        for(int i = 10; i < s.length();i++){
            pattern.erase(pattern.begin());
            pattern.push_back(s[i]);
            if(repeated_ans.find(pattern) != repeated_ans.end()){
                
                // repeated_ans[pattern] = 0 ,means no need to ans.push_back
                if(repeated_ans[pattern]){
                    ans.push_back(pattern);
                    repeated_ans[pattern] = 0;
                }
            }else{
                repeated_ans[pattern] = 1;
            }
        }
        return ans;
        
    }
};
