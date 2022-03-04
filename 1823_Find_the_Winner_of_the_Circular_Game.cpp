/*
https://en.wikipedia.org/wiki/Josephus_problem

source:
https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1152705/JavaC%2B%2BPython-4-lines-O(n)-time-O(1)-space

ex) n=5, k=2
(f[i] + k) % i = f[i+1], f[1] = 0

[x] (2 % 1 = 0) =>
[x,x] (2 % 2 = 0) =>
[x,x,x] (2 % 3 = 2) =>
[x,x,x,x] (4 % 4 = 0) =>
[1,2,3,4,5] (2 % 5 = 2)

2th element (0-indexed) is 3 so answer will be 3

*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};
