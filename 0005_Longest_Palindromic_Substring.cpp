class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) 
            return s;
            
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            // check aba type
            int len1 = expandPalindrom(s, i, i);
            
            // check acca type
            int len2 = 0;
            if(i+1 < s.size() && s[i] == s[i+1])
                len2 = expandPalindrom(s, i, i + 1);
            
            int len = max(len1, len2);

            if( len > end - start + 1){
                end = i + len/2;
                start = end - len + 1;
            }
        }
        string ans = "";
        for(int i = start; i <= end ; i++)
            ans += s[i];
        
        
        return ans;
    }

    int expandPalindrom(string s, int left, int right) {
        int curL = left, curR = right;

        // extend Palindrom from the center
        while (curL-1 >= 0 && curR+1 < s.size() && s[curL-1] == s[curR+1] ) {
            curL--;
            curR++;
        }
        return curR - curL + 1;
    }
    
};
