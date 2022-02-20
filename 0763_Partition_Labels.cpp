class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<vector<int>> letter_interval(26,{-1,-1});
        
        int ssize = s.size();
        for(int i = 0;i < ssize;i++){
            char index = s[i] - 'a';
            if(letter_interval[index][0] == -1)
                letter_interval[index][0] = i;
            letter_interval[index][1] = i;
        }
        
        //erase if the interval is [-1,-1];
        // for(int i = 0;i < letter_interval.size();){
        //     if(letter_interval[i][0] == -1)
        //         letter_interval.erase(letter_interval.begin() + i);
        //     else
        //         i++;
        // }
 
        letter_interval = merge(letter_interval);
        
        //erase if the first interval is [-1,-1];
        if(letter_interval[0][0] == -1)
            letter_interval.erase(letter_interval.begin());
        
        vector<int> interval_length;
        
        for(vector<int> i :letter_interval)
            interval_length.push_back(i[1] - i[0] + 1);
        
        return interval_length;
    }
    
    
    //Q56.Merge Intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> tmp {intervals[0][0],intervals[0][1]};
        vector<vector<int>> ans{tmp};

        for(int i = 1; i < intervals.size() ; i++){
            
            // if overlap
            if(ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else{
                tmp = {intervals[i][0],intervals[i][1]};
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
    
    
};
