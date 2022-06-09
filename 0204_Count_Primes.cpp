/*
Sieve of Eratosthenes

*/

class Solution {
public:
    int countPrimes(int n) {
        
        if(n == 1 || n == 0)
            return 0;   
          
        vector<bool> is_prime(n, true);
        is_prime[0] = false, 
        is_prime[1] = false;
         
        for (int i = 0; i < sqrt(n); i++) {
            if (is_prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    is_prime[j] = false;
                }    
            }    
        }
        
        int count = 0;
        for(int i = 0; i < n; i++)
            if(is_prime[i])
                count++;
        
        return count;
    }
};
