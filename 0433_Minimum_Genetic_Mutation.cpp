class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        queue<string> bfs_q;
        bfs_q.push(start);
        
        vector<bool> visited(bank.size(),false);
        
        int step = 0;
        while(!bfs_q.empty()){
            
            int n = bfs_q.size();
            while(n--){
                string cur = bfs_q.front();
                bfs_q.pop();

                for(int i = 0;i < bank.size();i++){
                    if(!visited[i]){
                        
                        int cur_diff = 0;
                        int end_diff = 0;
                        
                        // str compare
                        for(int j = 0;j < bank[i].length();j++){
                            
                            if(cur[j] != bank[i][j])
                                cur_diff++;
                            if(end[j] != bank[i][j])
                                end_diff++;
                            // if gene in the bank have more than one diff letter from cur
                            // means not a valid Mutation at this loop
                            if(cur_diff > 1)
                                break;
                        }
                        
                        if(cur_diff == 1){
                            if(end_diff == 0)
                                return step+1;
                            else{
                                visited[i] = true;
                                bfs_q.push(bank[i]);
                            }
                                
                        }
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};
