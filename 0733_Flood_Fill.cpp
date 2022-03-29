class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int original = image[sr][sc];
        
        if(original != newColor)
            fill(image, sr, sc, newColor, original);
        
        return image;
    }
    
    void fill(vector<vector<int>>& image , int r, int c, int& newColor ,int& original){
        if(r >= 0 && r < image.size() && c >= 0 && c < image[0].size() && image[r][c] == original)
            image[r][c] = newColor;
        else
            return;
        
        
        fill(image, r-1, c, newColor, original);
        fill(image, r, c-1, newColor, original);
        fill(image, r+1, c, newColor, original);
        fill(image, r, c+1, newColor, original);
        
        return;
        
    }
    
};
