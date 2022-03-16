/*
source:
https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/1149842/Simple-Solution-using-HashMap-w-Explanation-or-O(N)-O(1)-or-Beats-100
*/


class Solution {
public:
    unordered_map<char, int> mp;
    bool isAlienSorted(vector<string>& words, string order) {        
        // mapping letter to its corresponding index in order
        for(int i = 0; i < size(order); i++) 
            mp[order[i]] = i;  
        
        for(int i = 0; i < size(words) - 1; i++)
            if(!checkOrder(words[i], words[i + 1])) 
                return false;
        
        return true;        
    }    
    // checking if two words are lexicographically sorted
    bool checkOrder(string& a, string& b){
        int i = -1;
        
        while(++i < size(a) && i < size(b))
            if(mp[a[i]] != mp[b[i]]) 
                return mp[a[i]] < mp[b[i]];
        
        return size(a) <= size(b);
    }
};
