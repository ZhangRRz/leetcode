class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int numbers[n+1];
        
        for(int i = 1;i < n+1; i++){
            numbers[i] = 0;
        }
        for(vector<int> i: trust){
            numbers[i[0]] = -1;
            numbers[i[1]]++;
        }
        for(int i = 1;i < n+1; i++){
            if(numbers[i] == n-1)
                return i;
        }
        return -1;
    }
};
