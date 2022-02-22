class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int col = 0;
        for(char i:columnTitle){
            col *= 26;
            col += ( i - 'A' + 1);
        }
        
        return col;
    }
};
