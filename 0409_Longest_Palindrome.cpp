class Solution {
public:
    int longestPalindrome(string s) {
        vector<bool> letter(128,false);
        
        int ans;
        for(int i : s){
            letter[i] = !letter[i];     
            if(!letter[i])
                ans+=2;
        }
        for(int i : letter){
            if(i){
                ans++;
                break;
            }   
        }
        return ans;
    }
};
