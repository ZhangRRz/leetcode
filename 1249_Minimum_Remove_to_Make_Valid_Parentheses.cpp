class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> Parentheses;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                Parentheses.push(i);
            } 
            else if (c == ')') {
                if (!Parentheses.empty()) 
                    Parentheses.pop();
                else 
                    s[i] = '#';
                
            }
        }
        
        while (!Parentheses.empty()) {
            s[Parentheses.top()] = '#';
            Parentheses.pop();
        }
        
        // erase all #
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        
        return s;
    }
};
