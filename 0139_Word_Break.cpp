class Solution {
public:
    /*
    core ideal
    if now we at s[i],keep look back s[i]~s[i-1] and s[i]~s[i-2].....
    every time we try to find word "s[i]~s[i-n]" is in wordDict or not
    till s[i]~s[i-longestWord]
    
    after all of above are check
    
    move i to next

    */
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;

        int longestWord = 0;
        
        // check the longest word to reduce loop time
        for(string word : wordDict){
            longestWord = max(longestWord, (int)word.size());
        }

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i = 1;i <= s.size();i++){
            
            
            // if the longest word have b letter ,we only need look back at most n letter
            for(int j = i-1;j >= max(i-longestWord, 0);j--){
                if(dp[j]){
                    
                    string word = s.substr(j,i-j);
                    if(find(wordDict.begin(),wordDict.end(),word) != wordDict.end()){
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
    }
};
