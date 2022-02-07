class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        
        // XOR all letter in the string s and t
        for(int i = 0 ;i < s.size();i++){
            sum ^= t[i];
            sum ^= s[i];
        }
        
        // because t is one letter longer than s
        return sum ^ t.back();
    }
};
