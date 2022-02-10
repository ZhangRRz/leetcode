class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int s1 = text1.size();
        int s2 = text2.size();
        
        // make dp[0][0] useless
        int dp[s1+1][s2+1];
        
        
        for(int i = 0; i <= s1;i++)
            dp[i][0]=0;
        for(int i = 0; i <= s2;i++)
            dp[0][i]=0;
        
        
        
        
        // record result of text1[i-1]==text2[j-1]
        // at dp[i][j]
        
        for(int i = 1; i <= s1;i++){
            for(int j = 1; j <= s2;j++){
                
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                
            }
        }
        
        return dp[s1][s2];
    }
};
