class Solution {
public:
    void solve(int m,int n,int x,int y,int c1,int c2,vector<vector<int>>&image) {
        if(x<0 || x>=m || y<0 || y>=n || image[x][y] != c1)return;

        image[x][y] = c2;

        solve(m,n,x-1,y,c1,c2,image);
        solve(m,n,x,y-1,c1,c2,image);
        solve(m,n,x+1,y,c1,c2,image);
        solve(m,n,x,y+1,c1,c2,image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int color1 = image[sr][sc];

        if (color1 == color) {
            return image; // No need to do anything if the colors are the same
        }

         solve(m,n,sr,sc,color1,color,image);

        return image;
    }
};