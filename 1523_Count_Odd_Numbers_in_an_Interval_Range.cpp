class Solution {
public:
    int countOdds(int low, int high) {
        
        int ans = 0;
        if(low & 1 || high & 1) // low is odd or high is odd
            ans++;
        ans += (high - low) >> 1;// (high - low)/2
        
        return ans;
    }
};
