class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool ans = true;
        
        /*
        check_col_and_row(0,0, board);
        check_col_and_row(1,3, board);
        check_col_and_row(2,6, board);
        
        check_col_and_row(3,1, board);
        check_col_and_row(4,4, board);
        check_col_and_row(5,7, board);
        
        check_col_and_row(6,2, board);
        check_col_and_row(7,5, board);
        check_col_and_row(8,8, board);
        */
        
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
        
                if(!check_col_and_row(i*3+j,i+3*j, board))
                    return false;
                
                if(!check_3x3_sub_boxes(i*3,j*3, board))
                    return false;
            }
        }
                   
        return true;

    }
    
    bool check_col_and_row(int r,int c,vector<vector<char>>& board){
        
        bool appear_row[9] = {false,false,false,false,false,false,false,false,false,};
        bool appear_col[9] = {false,false,false,false,false,false,false,false,false,};
        
        // check
        for(int k = 0;k < 9;k++){
            char now = board[(r+k)%9][c];
            if(now != '.'){
                if(!appear_col[now - '1']){
                    appear_col[now - '1'] = true;
                }else{
                    return false;
                }
            }
            
            now = board[r][(c+k)%9];
            if(now != '.'){
                if(!appear_row[now - '1']){
                    appear_row[now - '1'] = true;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool check_3x3_sub_boxes(int r,int c,vector<vector<char>>& board){
        
        bool appear[9] = {false,false,false,false,false,false,false,false,false,};
        
        // check
        for(int k = 0;k < 3;k++){
            for(int l = 0;l < 3;l++){
                char now = board[r+k][c+l];
                if(now != '.'){
                    if(!appear[now - '1']){
                        appear[now - '1'] = true;
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    
};
