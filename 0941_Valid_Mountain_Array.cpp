class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int up = 0;
        int down  = 0;
        if(arr.size() <= 2){
            return false;
        }
        //check up part first
        for(int i = 0;i <= arr.size()-2;i++){
            if(arr[i] == arr[i+1])
                return false;
            else if(arr[i] < arr[i+1])
                up = 1;
            else{//up part of mountain ends, below is down part
                if(!up) return false; // if no up part ,return false;
                for(int j = i;j <= arr.size()-2;j++){
                    if(arr[j] == arr[j+1])
                        return false;
                    else if(arr[j] > arr[j+1])
                        down = 1;
                    else
                        return false;
                }
                if(up&&down)
                    return true;
                return false;
            }
        }
        return false;
    }
};
