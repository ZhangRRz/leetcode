/*
the same coding ideal with leecode Q1091
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        queue<pair<int, int>> q;
        
        // scan all 'O' at the most out of board
        // board[y][x]
        for(int x = 0;x < board[0].size() ;x++){
            for(int y = 0;y < board.size() ;y++){
                if(board[y][x] == 'O' && (x == 0 || x == board[0].size()-1 || y == 0 || y == board.size()-1)){
                    
                    board[y][x] = 'R';
                    q.push({x, y});
                }
            }
        }
        int qsize = q.size();
        
        while(qsize){
            
            while(qsize--){
                auto [currentx, currenty] = q.front();
                q.pop();

                // -  4  -
                // 3 now 1
                // -  2  -   check those 4 place if it is O or not
                if(currentx-1 > -1 && board[currenty][currentx-1] == 'O'){
                    board[currenty][currentx-1] = 'R';
                    q.push({currentx-1, currenty});
                }
                if(currentx+1 < board[0].size() && board[currenty][currentx+1] == 'O'){
                    board[currenty][currentx+1] = 'R';
                    q.push({currentx+1, currenty});
                }
                if(currenty-1 > -1 && board[currenty-1][currentx] == 'O'){
                    board[currenty-1][currentx] = 'R';
                    q.push({currentx, currenty-1});
                }
                if(currenty+1 < board.size() && board[currenty+1][currentx] == 'O'){
                    board[currenty+1][currentx] = 'R';
                    q.push({currentx, currenty+1});
                }

            }
            qsize = q.size();
        }
        for(int x = 0;x < board[0].size() ;x++){
            for(int y = 0;y < board.size() ;y++){
                
                // if O not be change to R means it is captured 
                if(board[y][x] == 'O' ){             
                    board[y][x] = 'X';
                }else if(board[y][x] == 'R' ){ 
                    board[y][x] = 'O';
                }
            }
        }

    }
};
