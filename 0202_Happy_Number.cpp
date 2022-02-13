class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        int num = n;
        vector<int> sum_vec;
        
        
        while(1){
            sum = 0;
            while(num != 0){
                sum += (num%10)*(num%10);
                num /= 10;
            }
            
            if(sum == 1)
                return true;
            
            //if this sum already in vector ,means it will be infinite loop
            // return false
            if(find(sum_vec.begin(), sum_vec.end(), sum) != sum_vec.end())
                return false;
            else
                sum_vec.push_back(sum);

            num = sum;
        }
        
        return false;
        
    }
};
