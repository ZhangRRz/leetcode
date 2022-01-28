class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        if(s.length() < p.length())
            return ans;
        
        
        vector<int> sletter(26,0),pletter(26,0);

        // count the appearing times of all letter in str p
        for(int i = 0 ;i<p.length();i++){
            
            //calc the ascii code to know index
            pletter[p[i]-'a']++;
            sletter[s[i]-'a']++;
        }
        
        int i = p.length()-1;

        // i - p.length() + 1 is the start of the window
        // i is the end of window
        
        while (i < s.length()){
            
            if(pletter == sletter ){
                ans.push_back(i - p.length() + 1);
            }
            
            if(i == s.length()-1)
                return ans;
            
            sletter[s[i - p.length() + 1 ] - 'a']--;
            sletter[s[i+1] - 'a']++;
            i++;

        }
        
        return ans;
        
    }
};
