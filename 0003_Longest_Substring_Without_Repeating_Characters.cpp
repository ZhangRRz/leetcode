class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> prev_char(256, -1);
        
        int max_substr = 0;
        int start = -1;
        
         for(int i = 0; i < s.size(); i++){
             
            if (prev_char[s[i]] > start)
                start = prev_char[s[i]];
             
            prev_char[s[i]] = i;
            max_substr = max(max_substr, i - start);
        }
        
        return max_substr;      
    }
};
