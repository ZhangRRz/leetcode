class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
         // if start is already deadends
        if(find(deadends.begin(),deadends.end(),"0000") != deadends.end()) 
            return -1;
        if(target == "0000") 
            return 0;

        unordered_set<string> stuck(begin(deadends), end(deadends));
        unordered_set<string> visited;
        
        queue<string> bfs_q;
        bfs_q.push("0000");
        visited.insert("0000");
        
        int turn_lock = 0;
        while(!bfs_q.empty()){
            
            
            int n = bfs_q.size();
            while(n--){
                string cur = bfs_q.front();
                bfs_q.pop();
                
                for(int i = 0;i < 4;i++){
                    string turn_a_digit = cur;
                    // forward
                    turn_a_digit[i] = '0' + (turn_a_digit[i] - '0' + 1) % 10;
                    if(visited.find(turn_a_digit) == visited.end() && stuck.find(turn_a_digit) == stuck.end()){
                        if(turn_a_digit == target) 
                            return turn_lock+1;
						else {
                            bfs_q.push(turn_a_digit);
                            visited.insert(turn_a_digit);
                        }
                    }
                    
                    
                    // backward
                    turn_a_digit = cur;
                    turn_a_digit[i] = '0' + (turn_a_digit[i] - '0' - 1 + 10) % 10;
                    if(visited.find(turn_a_digit) == visited.end() && stuck.find(turn_a_digit) == stuck.end()){
                        if(turn_a_digit == target) 
                            return turn_lock+1;
						else {
                            bfs_q.push(turn_a_digit);
                            visited.insert(turn_a_digit);
                        }
                    }
                    
                }
                
                
            }
            turn_lock++;
        }
        
        return -1;
        
    }
};
