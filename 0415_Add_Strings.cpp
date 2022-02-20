class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int carry = 0;

        if(num1.length() < num2.length()){
           swap(num1,num2);
        }
        int smax = num1.length() - 1;
        int smin = num2.length() - 1;
        
        
        while(smin != -1){
            int digit = (num2[smin]-'0' + num1[smax]-'0' + carry);
            
            carry = digit/10;
            num1[smax] = '0' + digit%10;
            
            smin--;
            smax--;
        }
        while(carry && smax != -1){
            int digit = num1[smax]-'0' + carry;
            
            carry = digit/10;
            num1[smax] = '0' + digit%10;
    
            smax--;
        }
        if(carry)
            num1.insert(0, "1");
        
        
        
        return num1;
    }
};
