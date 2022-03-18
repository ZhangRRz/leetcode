class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int letter[26] = {0};
        for(int i = 0;i < s.length();i++)
            letter[s[i] - 'a']++;
        
        for(int i = 0;i < t.length();i++)
            letter[t[i] - 'a']--;  
        
        for(int i = 0;i < 26;i++)
            if(letter[i])
                return false;
        return true;
        
    }
};
