
class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        addingpar(ans, "", n, 0);
        
        return ans;
    }
    void addingpar(vector<string> &ans, string str, int LP_num, int RP_num){
        
        // means all ( and ) we can put is done
        if(LP_num==0 && RP_num==0) {
            ans.push_back(str);
            return;
        }
        
        
        if(RP_num > 0)
            addingpar(ans, str+")", LP_num, RP_num-1);
        
        // if put a ( then LP_num-1  and  RP_num+1 means we can put one more )
        if(LP_num > 0)
            addingpar(ans, str+"(", LP_num-1, RP_num+1); 
    }
};
