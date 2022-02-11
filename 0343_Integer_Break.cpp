/*
math problem 
the more 3 we have ,the bigger product we get

can also be sloved using DP skill

*/


class Solution {
public:
    int integerBreak(int n) {
        
        if(n == 2 || n == 3)
            return n-1;
        else if(n%3 == 1)
            return pow(3,n/3-1)*4;
        else if(n%3 == 2)
            return pow(3,n/3)*2;
        else
            return pow(3,n/3);
    }
};
