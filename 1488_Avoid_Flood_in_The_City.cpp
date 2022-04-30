class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        unordered_map<int,int> full_lack;
        priority_queue<int, vector<int>, greater<>> zerodays;
        
        int n = rains.size();
        vector<int> ans(n,-1);
        for(int i = 0;i < n;i++){
            
            const int cur_lake = rains[i];
            if(cur_lake == 0){
                zerodays.push(i);
                ans[i] = 1;
                continue;
            }
            
            if(full_lack.find(rains[i]) == full_lack.end()){
                full_lack[cur_lake] = i;
            }else{

                vector<int> temp;
                while(!zerodays.empty() and zerodays.top() < full_lack[rains[i]]){
                    temp.push_back(zerodays.top());
                    zerodays.pop();
                }

                if(zerodays.empty()){
                    return {};
                }
                full_lack[cur_lake] = i;

                ans[zerodays.top()] = rains[i];
                zerodays.pop();

                for(auto it : temp){
                    zerodays.push(it);
                }
            }
            
            
        }
        
        return ans;
    }
};
