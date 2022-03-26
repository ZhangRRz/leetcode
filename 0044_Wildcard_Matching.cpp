class Solution {
public:
    bool isMatch(string s, string p) {
        
        //=============================
        // special case
        //=============================
        if(p.compare("*") == 0)
            return true;
        if(p.compare("") == 0){
            if(s.compare("") == 0)
                return true;
            else
                return false;
        }
        
        // if have '*' ,we cant torrent mismatch
        bool fault_torrent = false;
        
        //=============================
        // use split, store all the part of pattern in p_vec
        // and indicate p[0] is '*' or not '*'
        //=============================
        vector<string> p_vec;
        str_split(p_vec,p);
        
        if(p[0] == '*')
            fault_torrent = true;
        
        //=============================
        // start the pattern matching;
        //=============================
        int j = 1;
        int i = 0;
        for(;i < s.size() && j < p_vec.size(); i++){
            
            bool match = true;
            for(int k = 0;k < p_vec[j].length();k++){
                
                if(k+i >= s.length())
                    return false;
                
                if(p_vec[j][k] != s[k+i] && p_vec[j][k] != '?'){
                    if(!fault_torrent){
                        return false;
                    }
                    else{
                        match = false;
                        break;
                    }
                }
                
            }
            //=============================
            // here means pattern p_vec[j] is match,
            // let i increase to p_vec[j].length()-1 ,-1 beacause we have i++ in for loop
            // j++ means we start match next pattern in p_vec
            //=============================
            // why turn on fault_torrent?
            // remember,we split pattern if see '*'
            // so if go to next pattern ,means is must have '*' before the pattern 
            //=============================
            if(match){
                i += p_vec[j].length()-1;
                j++;
                fault_torrent = true;
            }
            // if not match ,just do nothing
            
            
        }
        // after exit the for loop
        // we have serveral condition to determit result
        //=============================
        // 1. not all of pattern are matched 
        //=============================
        if(j != p_vec.size())
            return false;
        //=============================
        // 2. i == s.length() and j == p_vec.size()
        // means all of pattern are matched and string s also end
        //=============================
        // 3. i != s.length() and p end with '*'
        // means all of pattern are matched 
        // but s still have some letter not match
        // those letter can match with last '*'
        //=============================
        else if(i == s.length() || p[p.length()-1] == '*')
                return true;
        //=============================
        // 4. i != s.length() and p "NOT" end with '*' but have '*' in the middle
        // means all of pattern are matched 
        // but s still have some letter not match
        // we just match the last pattern in p_vec with tail of s again
        // the tail should as long as p_vec.back().length()
        //=============================
        else if(i != s.length() && (p[0] == '*' || p_vec.size() >= 3)){
            
            string last_pattern = p_vec.back();
            int last_part_index = s.size() - p_vec.back().length();
            
            for(int k = 0;k < p_vec.back().length();k++){
                if(last_pattern[k] != s[last_part_index+k] && last_pattern[k] != '?')
                        return false;
            }
            return true;
            
        }
        //=============================
        // all the other are false
        //=============================
        else
            return false;
        
        
    }
    
    
    void str_split(vector<string>& p_vec,string str_to_split){
        
        //=============================
        // split if see '*'
        // example:
        // if p is *aa*?c*asd
        // p_vec will be ["*","aa","?c","asd"]
        //=============================
        string tmp = "";
        if(str_to_split[0] == '*')
            p_vec.push_back("*");
        else
            p_vec.push_back("-");
        
        for(int i = 0;i < str_to_split.size(); i++){
            if(str_to_split[i] == '*'){
                if(tmp != ""){
                    p_vec.push_back(tmp);
                    tmp = "";
                }      
            }else{
                tmp += str_to_split[i];
            }
        }
        if(tmp != ""){
            p_vec.push_back(tmp);
            tmp = "";
        }
        
        return;
    }
    
    
};
