/*
two-ends BFS
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wlist(wordList.begin(),wordList.end());
        unordered_set<string> begin_set;
        unordered_set<string> end_set;
        
        if(!wlist.count(endWord)) 
            return 0;
        
        int n = beginWord.size();
        int step = 0;
        begin_set.insert(beginWord);
        end_set.insert(endWord);
        
        while(!begin_set.empty() && !end_set.empty()){
            step++;
            if(begin_set.size()>begin_set.size())
                swap(begin_set,end_set);
            
            unordered_set<string> tmp;
            
            for(string cur_str:begin_set){
                for(int i = 0;i < n;i++){
                    char original_char = cur_str[i];
                    // replace cur_str[i] to find one-char-different string
                    for(int k = 0;k < 26;k++){
                        cur_str[i] = 'a'+ k;
                        
                        // if find cur_str in end_set == two set have common string
                        // means word ladder is found
                        if(end_set.count(cur_str))
                            return step + 1;
                        if(!wlist.count(cur_str)) 
                            continue;
                        // delete cur_str in wlist so it wont be visited again 
                        wlist.erase(cur_str);
                        tmp.insert(cur_str);
                    }
                    cur_str[i] = original_char;
                }
            }
            begin_set = tmp;
        }
        return 0;
    }
};
