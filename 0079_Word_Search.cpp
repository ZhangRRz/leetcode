class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        bool ans = false;
        
        for(int i = 0 ;i < board.size(); i++){
            for(int j = 0;j < board[i].size(); j++){
                if(ans)
                    return ans;
                if(board[i][j] == word[0])
                    findword(i,j,board,word,ans);
            }
        }
        
        return ans;
    }
    
    
    void findword(int i, int j , vector<vector<char>>& board, string word,bool& ans){
        
        word.erase(word.begin());
        
        char marked = board[i][j];
        board[i][j] = '#';
        
        if(ans || !word.length()){
            ans = true;
            return;
        }else{
            
            
            if(i-1 > -1 && board[i-1][j] == word[0]){
                findword(i-1,j,board,word,ans);
            }
            if(j-1 > -1 && board[i][j-1] == word[0]){
                findword(i,j-1,board,word,ans);
            }
            if(i+1 < board.size() && board[i+1][j] == word[0]){
                findword(i+1,j,board,word,ans);
            }
            if(j+1 < board[i].size() && board[i][j+1] == word[0]){
                findword(i,j+1,board,word,ans);
            }
            
            
        }
        
        board[i][j] = marked;

    }
    
};
