/*
idea
https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation

*/


class Solution {
public:
    string multiply(string num1, string num2) {
        int n1s = num1.size();
        int n2s = num2.size();
        string ans(n1s + n2s, '0');
        
        for(int i = n1s - 1; i>=0 ;i--){
            for(int j = n2s - 1; j >= 0; j--){
                int product = (ans[i + j +1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                
                ans[i+j+1] = product % 10 + '0';
                ans[i+j] += product / 10 ;
            }
        }
        
        // ignore leading 0
        for(int i = 0; i < n1s + n2s; i++){
            if(ans[i] !='0')
                return ans.substr(i);
        }
        
        return "0";
    }
};
