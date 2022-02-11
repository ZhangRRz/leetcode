class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        
        if(left == right)
            return left;
        
        int zerobit = ceil(log2(right-left));
        
        return  ((left>>zerobit)<<zerobit)&right;
        
    }
};
