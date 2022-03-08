class Solution {
public:
    double myPow(double x, int n) {
        
        if(x == 1 || x == 0)
            return x;
        if(n == 0)
            return 1;
        
        x = (n > 0)? x : 1/x;
        long n_2 = abs((long)n);
        
        double ans = 1;
        
        while(n_2){
            
            ans *= ((n_2%2)? n_2%2 * x : 1);
            n_2 /= 2;
            x *= x;
        }
        return ans;
    }
};
