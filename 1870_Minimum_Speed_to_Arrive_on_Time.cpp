class Solution{
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int n = dist.size();
        if (hour <= (double)(n - 1))
            return -1;
        
        int left = 1, right = 1e7;
        int mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            
            double time = 0;
            for (int i = 0; i < dist.size() - 1; i++)
                time += (dist[i] + mid - 1) / mid;

            // the last train is no need to calculate ceil()
            time += ((double)dist.back()) / mid;
            
            
            if (time <= hour)
                right = mid;
            else
                left = mid + 1;
        }
        
        return right;
    }
};
