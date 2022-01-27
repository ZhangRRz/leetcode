class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 2){
            return min(height[1],height[0]);
        }
        
        // first let both have greatest distance to make length longest;
        // then gradually move shorter side closer and calc. 
        int l = 0, r = height.size()-1; 
        int maxContainer = 0;
        while(l < r){
            
            int result_of_this_loop = min(height[l],height[r])*(r-l);
            if(maxContainer < result_of_this_loop)
                maxContainer = result_of_this_loop;
            
            int move;
            // move the shorter side
            if(height[l] > height[r]){ //r is shorter,move r
                move = r-1;
                // skip all element that shorter than r while we moving r
                while(height[r] > height[move] && l < move)
                    move--;
                r = move;
            }else{  //l is shorter,move l
                // skip all element that shorter than l while we moving r
                move = l+1;
                while(height[l] > height[move] && move < r)
                    move++;
                l = move;
            }
        }
        return maxContainer;
    }
};
