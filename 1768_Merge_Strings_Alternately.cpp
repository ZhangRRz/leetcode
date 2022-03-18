class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        string longer = word1;
        string shorter = word2;
        
        if(word1.length() < word2.length()){
            longer = word2;
            shorter = word1;
        }
        int index;
        for(index = 0; index < shorter.length();index++){
            ans += word1[index];
            ans += word2[index];
        }
        
        if(index < longer.length())
            ans += longer.substr(index);
        
        return ans;
    }
};
