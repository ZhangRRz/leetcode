class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        
        const int max_pro_size = 100001;
        // index i of max_pro means max profit of difficulty i 
        int max_pro[max_pro_size] = {0}, sum = 0;
        
        for(int i = 0; i < difficulty.size(); i++)
            max_pro[difficulty[i]] = max(max_pro[difficulty[i]], profit[i]);
        
        for(int i = 1; i < max_pro_size; i++)
            max_pro[i] = max(max_pro[i], max_pro[i - 1]);
        
        for(int i = 0; i < worker.size(); i++)
            sum += max_pro[worker[i]];
        
        return sum;
    
    }
};
