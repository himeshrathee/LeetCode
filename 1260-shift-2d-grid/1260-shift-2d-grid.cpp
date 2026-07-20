class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n= grid[0].size();
         k= k % (m*n); 
        vector<int>v ; 
        for(int i= 0;i<m;i++){
            for(int j= 0;j<n;j++){
                v.push_back(grid[i][j]) ; 
            }
        }
        vector<int>t;
        for(int i= n*m -k; i<n*m;i++){
         t.push_back(v[i]); 
        } 
        for(int i=n*m-1;i>= k ;i--){
            v[i]= v[i-k]; 
        }
        for(int i= 0 ; i<k;i++){
            v[i]= t[i] ;
        }
        int h= 0;
         for(int i= 0;i<m;i++){
            for(int j= 0;j<n;j++){
                 grid[i][j] = v[h++] ; 
            }
        }
        return grid ; 
    }
};