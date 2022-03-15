class Solution {
public:
    string interpret(string command) {
        
        string ans = "";
        for(int i = 0;i < command.length();){
             if(command[i] == 'G'){
                ans += "G";
                i++;
            }else if(command.substr(i,2) == "(a"){
                ans += "al";
                i += 4;
            }else{
                ans += "o";
                i += 2;
            }
                
        }
        return ans;
    }
};
