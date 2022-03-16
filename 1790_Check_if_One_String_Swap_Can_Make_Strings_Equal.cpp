class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> swap_index;
        
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i])
                swap_index.push_back(i);
        }

        if(swap_index.size() == 2) 
            swap(s1[swap_index[0]], s1[swap_index[1]]);
        
        return s1 == s2;
    }
};
