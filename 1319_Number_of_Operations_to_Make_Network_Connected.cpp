class Solution {
    
private:    
    vector<int>parent;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c_size = connections.size();
        
        // not enough connections
        if (c_size < n-1) 
            return -1;
        
        parent = vector<int>(n);
        // first assume we have n group(means each computer is a group and the group is only itself)
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // traversal the connections,every element in connection is look like [a,b]
        for (int i = 0; i < c_size; i++) {
            int parent_of_a = findparent(connections[i][0]);
            int parent_of_b = findparent(connections[i][1]);
            
            // if [a,b] ,a have different parent from b
            // make their parent become the same group
            if (parent_of_a != parent_of_b) 
                parent[parent_of_b] = parent_of_a;
        }
        
        int number_of_group = 0;
        for (int i = 0; i < n; i++)
            // if parent[i] is i itself,means this is a group
            if (parent[i] == i)
                number_of_group++;
        
        return number_of_group - 1;
    }
    
    int findparent(int i) {
        
        if(parent[i] == i)
            return i;
        else
            return findparent(parent[i]);
    }
};
