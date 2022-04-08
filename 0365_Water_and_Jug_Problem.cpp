class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        

        if(targetCapacity > jug1Capacity + jug2Capacity)
            return false;
        
        // z = k * gcd(x, y)
        if(targetCapacity == 0 || targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0 )
            return true;
        
        return false;
    }
        
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};
