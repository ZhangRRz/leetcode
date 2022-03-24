class Solution {
public:
    int trap(vector<int>& height) {

        // local_high_index store all local high
        // cur_highest_index store highest local high in local_high_index
        // local high is the element satisfies both 2 condition
        // 1. height[i] >= height[i-1]
        // 2. height[i] >= height[i+1]
        // but first and last element should do different check
        vector<int> local_high_index;
        int cur_highest_index;
        int ans = 0;
        int n = height.size();
        
        if(n < 3)
            return 0;
        //===============================================
        // find all local high
        //===============================================
        // first element;
        if(height[0] > height[1]){
            local_high_index.push_back(0);
            cur_highest_index = 0;
        }
        
        // element in the middle of vector height
        for(int i = 1;i < n - 1;i++ ){
            if(height[i] >= height[i-1] && height[i] >= height[i+1]){

                if (!local_high_index.empty())
                    check_local_high(i, cur_highest_index, local_high_index, height);
                else
                    cur_highest_index = i;
                local_high_index.push_back(i);

            }
        }
        // last element;
        if(!local_high_index.empty() && height[n-2] < height[n-1]){
            check_local_high(n-1, cur_highest_index, local_high_index, height);
            local_high_index.push_back(n-1);
        }
        
        //===============================================
        // index between 2 local_high_index means it will have Rain Water
        // then we judge which side of local_high is shroter,and use result as limit
        // if limit - height[j] > 0 ,means this inde have Rain Water
        //===============================================
        
        if(local_high_index.size() >= 2){
            
            for(int i = 0;i < local_high_index.size() - 1;i++){
                
                int j = local_high_index[i];
                // then we judge which side of local_high is shorter
                // use it as limit
                int limit = min(height[local_high_index[i]], height[local_high_index[i+1]]);
                
                for(;j < local_high_index[i+1];j++){
                    if(limit - height[j] > 0)
                        ans += (limit - height[j]);
                }
                
            }
        }
        
        return ans;
        
    }

    void check_local_high(int cur,int& cur_highest_index,
                          vector<int>& local_high_index,vector<int>& height){
        //===============================================
        // if we find current local high is higher than previous local high in local_high_index
        // we pop previous local high
        // loop check till we reach cur highest local high or 
        // current local high is NOT higher than previous local high
        //===============================================
        while(height[cur] > height[local_high_index.back()]){
            
            if(local_high_index.back() == cur_highest_index)
                break;
            else
                local_high_index.pop_back();
        }
        //===============================================
        // then check current local high is higher than highest local high
        // update the cur_highest_index
        //===============================================
        if(height[cur] >= height[cur_highest_index])
            cur_highest_index = cur;

        return;
    }
};
