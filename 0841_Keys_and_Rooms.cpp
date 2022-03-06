class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<int>able(rooms.size(),0);
        dfs(0,rooms,able);
        
        for(int i = 0;i < rooms.size();i++){
            if(!able[i])
                return false;
        }
        return true;
    }
    
    void dfs(int cur_room,vector<vector<int>>& rooms,vector<int>&able){
        able[cur_room]=1;
        
        for(int i : rooms[cur_room]){
            if(!able[i]){
                dfs(i,rooms,able);
            }
        }
    }
};
