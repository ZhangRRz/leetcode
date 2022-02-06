class Solution {
public:
    int uniquePaths(int m, int n) {
    
        
        // because bot can only go down or right ,this is just a math question for C(n, r)
        // means n!/[r!(n-r)!]
        // total the bot need are go down m-1 time and go right n-1 time,then it must reach the goal
        // so if m = 3, n =7 then C(n-1+m-1 , n-1) = C(2+6,6)
        // we only need calculate (7*8) / 2!
        
        
        long ans = 1;
        
        int s = max(m-1,n-1);
        
        // i is for 8*7
        // (n-1+m-1 - i + 1) is for 1*2
        for(int i = s+1 ; i < n-1+m-1 + 1; i++){ 
            
            ans = ans * i /(i-s);
        }
        
        return ans;
    
    
    
    }
    
    
    
    // below is solution 2;
    /*
    int uniquePaths(int m, int n) {
        
        if(min(m,n) == 1)
            return 1;
        
        
//         assume we have  7*3 grid
//         first we create a vector length = 7 and all element are one
//         1,1,1,1,1,1,1,1
//         this also means that in 7*1 grid, how many Unique Paths we have for reaching road[0][i]
        
//         then do road[i] = road[i] + road[i-1]; vector will become
//         1,2,3,4,5,6,7
//         this time represent that in 7*2 grid ,how many Unique Paths we have for reaching road[1][i]
        
//         do road[i] = road[i] + road[i-1]; again, vector will become
//         1,3,6,10,15,21,28
//         this time represent that in 7*3 grid ,how many Unique Paths we have for reaching road[2][i]
        
//         so just loop as many as the height of grid
//         then return road.back();
        
        
        
        vector<int> road(m,1);
        
        for(int j = 1; j < n; j++){
            
            for(int i = 1;i < m;i++){
                road[i] = road[i] + road[i-1];
            }
        }
        
        return road.back();
    }
    */
};
