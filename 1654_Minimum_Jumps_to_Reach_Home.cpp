class Solution {

public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        if(x == 0)
            return 0;
        int max_ele_forbi =*max_element(forbidden.begin(), forbidden.end());
        int search_upper_bound = a + b + max(x, max_ele_forbi);
        
        // +1 is important
        vector<vector<bool>> visited(search_upper_bound+1, vector<bool>(2,false));
        
        for(int i = 0;i < forbidden.size();i++){
            visited[forbidden[i]][0] = true;
            visited[forbidden[i]][1] = true;
        }
        visited[0][0] = true;
        
        queue<pair<int,bool>> bfs_q;
        bfs_q.push({0, false});

        int jump = 0;
        
        while(!bfs_q.empty()){
            
            int n = bfs_q.size();
            jump++;
            while(n--){
                int cur = bfs_q.front().first;
                bool is_back = bfs_q.front().second;
                bfs_q.pop();
                
                // check forward first
                int next = cur + a;
                if(next <= search_upper_bound && !visited[next][0]){
                    bfs_q.push({next, false});
                    visited[next][0] = true;
                    if(next == x) 
                        return jump;
                }

                // if previous is not back ,check backward
                next = cur - b;
                if(is_back == false && next >= 0 && !visited[next][1]){
                    bfs_q.push({next, true});
                    visited[next][1] = true;
                    if(next == x) 
                        return jump;
                }

            }
        }
        return -1;
    }
};
