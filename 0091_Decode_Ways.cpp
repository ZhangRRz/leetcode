class Solution {
public:
    int numDecodings(string s) {
        if(!s.size() || !(s[0]-'0'))
            return 0;
        else if(s.size() == 1)
            return 1;
        
        //first check s[0],s[1] then create ans[0],ans[1]
        vector<int> ans{1};
        if( s[1] == '0'){
                if( s[0] == '2' || s[0] == '1')
                    ans.push_back(ans[0]);
                else
                    return 0;
                
        }else{
            if(s[0] == '2' && s[1] - '6'  < 1)
                ans.push_back(ans[0]+1);
            else if(s[0] == '1')
                ans.push_back(ans[0]+1);
            else
                ans.push_back(ans[0]);
            
        }

        
        // ans[i] = ans[i-1]+ans[i-2]
        // let i start from s[1] 
        for(int i = 2; i < s.size();i++){
            
            if( s[i] == '0'){
                if( s[i-1] == '2' || s[i-1] == '1')
                    ans.push_back(ans[0]);
                else
                    return 0;
                
            }
            else{
                if(s[i-1] == '2' && s[i] - '6' < 1)
                    ans.push_back(ans[1]+ans[0]);
                else if(s[i-1] == '1')
                    ans.push_back(ans[1]+ans[0]);
                else
                    ans.push_back(ans[1]);
            }
            
            
            ans.erase(ans.begin());
        }
        
        return ans.back();
    }
};
