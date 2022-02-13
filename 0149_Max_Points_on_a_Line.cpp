class Solution {
    
public:
    int maxPoints(vector<vector<int>>& points) {
        
        // use slope to categorize every node and line;
        vector<float> m;
        vector<vector<int>> point_set;
        vector<int> point_set_for_no_slope;
    
        
        if(points.size() < 3)
            return points.size();
        
        int max_num_of_point_of_a_line = 0;
        
        for(int i = 0 ; i < points.size()-1 ; i++){
            for(int j = i + 1 ; j < points.size(); j++){
                
                // calc slope  X/Y
                // if y1-y2 == 0
                if(points[i][1] - points[j][1] == 0){
                    if(point_set_for_no_slope.size() == 0)
                        point_set_for_no_slope.push_back(i);
                    
                    point_set_for_no_slope.push_back(j);
                }
                else{// if y1-y2 != 0
                    float cur_m = ((points[i][0]-points[j][0])/1.0)/(points[i][1]-points[j][1]);
                
                    vector<float>::iterator it = find(m.begin(), m.end(), cur_m);
                    if(it == m.end()){
                        m.push_back(cur_m);

                        vector<int> temp_point{i,j};
                        point_set.push_back(temp_point);
                    }
                    else{

                        int index = std::distance(m.begin(), it);
                        point_set[index].push_back(j);

                    }
                }
                
            }
            
            // determint max_num_of_point_of_a_line
            int cur_max = point_set_for_no_slope.size();
            max_num_of_point_of_a_line = max(max_num_of_point_of_a_line,cur_max);
            
            for(int i = 0 ; i < point_set.size() ; i++){
                int cur_max = point_set[i].size();
                max_num_of_point_of_a_line = std::max(max_num_of_point_of_a_line, cur_max);
            }
            
            //clear all the vector for next point
            m.clear();
            point_set.clear();
            point_set_for_no_slope.clear();
            
        }

        
        return max_num_of_point_of_a_line;
        
    }
};
