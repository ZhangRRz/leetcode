class Solution {
public:
    vector<vector<char>> table{{'a','b','c'},{'d','e','f'},{'g','h','i'},
                               {'j','k','l'},{'m','n','o'},{'p','q','r','s'},
                               {'t','u','v'},{'w','x','y','z'}};
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string tmp;
        if(digits.size())
            letter(digits, ans, tmp);
        
        return ans;
    }
    
    // all are pass by reference
    void letter(string& digits, vector<string>& ans, string& tmp){
        
        
        if(digits.size()){

            //record first of digit
            char now_num = digits[0];
            digits.erase(digits.begin());
            
            for(int i = 0; i < table[now_num -'0'-2].size(); i++){
                
                // concat the letter to tmp
                tmp += table[now_num -'0'-2][i];
                
                letter(digits, ans, tmp);
                
                // pop the letter to tmp we just concat
                tmp.pop_back();

            }
            // insert the first of digit we just erase after for loop
            // to keep the same as previous recursion
            digits.insert(digits.begin(), now_num);
        }else
            ans.push_back(tmp);
        
    }
    
};
