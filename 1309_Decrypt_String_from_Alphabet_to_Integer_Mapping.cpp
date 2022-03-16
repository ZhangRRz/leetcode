class Solution {
public:
    string freqAlphabets(string s) {
        
        int sl = s.length();
        string ans = "";
        int index = 0;
        
        while(index < sl){
            if(index + 2 < sl && s[index + 2] == '#') {
                int shift = (s[index] - '0')*10 + (s[index+1] -'0') - 1;
                ans += ('a' + shift);
                index += 3;
            }
            else {
                ans += ('a' + s[index]- '1');
                index++;
            }
        }
        
        
        
        return ans;
    }
};
