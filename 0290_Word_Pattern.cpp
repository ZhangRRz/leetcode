class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char,string> pattern_map_word;
        unordered_map<string,char> word_map_pattern;
        
        int now_s_index = 0;
        
        for(char i : pattern){
            
            string word = "";
            while(s[now_s_index] != ' ' && now_s_index < s.length()){
                word += s[now_s_index];
                now_s_index++;
            }
            now_s_index++;
            
            //use pattern to check if word is correct or not
            if(pattern_map_word.find(i) != pattern_map_word.end()){
                if(pattern_map_word[i] != word)
                    return false;
            }
            else
                pattern_map_word[i] = word;
            
            //use word to check if pattern is correct or not
            if(word_map_pattern.find(word) != word_map_pattern.end()){
                if(word_map_pattern[word] != i)
                    return false;
            }
            else
                word_map_pattern[word] = i;
                
        }
        
        
        // if pattern is shorter than s
        if(now_s_index == s.length()+1)
            return true;
        else
            return false;

    }
};
