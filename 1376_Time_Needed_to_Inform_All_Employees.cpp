class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int max_total_time = 0;
        for(int i = 0;i < manager.size();i++){
            if(informTime[i] == 0){
                max_total_time = max(find_manager(manager,informTime,i), max_total_time);
            }
        }
        
        
        return max_total_time;
        
    }
    
    int find_manager(vector<int>& manager, vector<int>& informTime, int i){
        if(manager[i] != -1){
            informTime[i] += find_manager(manager,informTime,manager[i]);
            manager[i] = -1;
        }
        
        return informTime[i];
    }
    
    
};
