/*
OJ: https://leetcode.com/contest/weekly-contest-214/problems/sell-diminishing-valued-colored-balls/
Author: github.com/lzl124631x
*/

class Solution {
    map<int, int, greater<>> m;
    bool valid(int M, int T) {
        for (auto &[n , cnt] : m) {
            if (n <= M) break;
            T -= (long)cnt * (n - M);
            if (T <= 0) return true;
        }
        return T <= 0;
    }
public:
    int maxProfit(vector<int>& A, int T) {
        long ans = 0, mod = 1e9+7, L = 0, R = *max_element(begin(A), end(A));
        for (int n : A) m[n]++;
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(M, T)) L = M + 1;
            else R = M - 1;
        }
        for (auto &[n , cnt] : m) {
            if (n <= L) break;
            T -= cnt * (n - L);
            ans = (ans + (n + L + 1) * (n - L) / 2 % mod * cnt % mod) % mod;
        }
        if (T) ans = (ans + L * T % mod) % mod;
        return ans;
    }
};
