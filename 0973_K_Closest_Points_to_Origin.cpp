class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        if(k == points.size())
            return points;

        priority_queue<pair<int, int>> max_heap;
        unordered_map<int, double> dis;
        
        // build map <index of point , dis of point to (0,0)>
        for (int i = 0 ;i < points.size(); i++) {
            
            double x = abs(points[i][0]);
            double y = abs(points[i][1]);
            dis[i] = y*y + x*x;
        }

        for (auto p : dis) {
            max_heap.push({p.second, p.first});
            
            if(max_heap.size() > k)
                max_heap.pop();
        }
        

        // max_heap.top().first is dis
        // max_heap.top().second is index of point
        vector<vector<int>> ans;
        while (!max_heap.empty()) {

            ans.push_back(points[max_heap.top().second]);
            max_heap.pop();
            
        }
        return ans;
    }
};
