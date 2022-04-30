/*
https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template
*/

class Solution {
public:    
   int nthUglyNumber(int k, int A, int B, int C) {
       
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / gcd(a, b);
        long bc = b * c / gcd(b, c);
        long ac = a * c / gcd(a, c);
        long abc = a * bc / gcd(a, bc);
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < k) 
                lo = mid + 1;
            else

                hi = mid;
        }
        return lo;
    }
};
