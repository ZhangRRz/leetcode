/*
idea:
https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/discuss/534631/C%2B%2B-beats-100-with-__builtin_popcount

https://tmt514.gitbooks.io/the-code-tactics-book/content/2.5/popcount.html

*/


class Solution {
public:
    
    static bool customCompare(const int& a, const int& b){
        int num_of_bit1_a = __builtin_popcount(a);
        int num_of_bit1_b = __builtin_popcount(b);
        
        if(num_of_bit1_a == num_of_bit1_b)
            return a < b;
        return num_of_bit1_a < num_of_bit1_b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(), customCompare);
        return arr;
    }
};
