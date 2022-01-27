class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        str_processing(s);
        str_processing(t);       
        return s==t;
    }
    
    void str_processing(string& str){
        int first = 0;
        int second = 1;
        while(second < str.length()){
            // if str[second] == backspace ,change str[first] to '#' means delete
            if(str[second] == '#'){
                
                // if str[first] is already a '#' ,need first-- to find closest alphabet to delete
                while( str[first] == '#' && first != 0)
                    first--;
                
                str[first] = '#';
            }else{ //s[second] is a-z
                first = second;
            }
            second++;
        }
        //delete all "#"
        str.erase(remove(str.begin(), str.end(), '#'), str.end());
    }
};
