class Solution {
public:
   void bfs(int i,int j, vector<vector<bool>>&v,vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    v[i][j]=true;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(q.size()>0){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        // top
        if(r>0){
            if(v[r-1][c]==false && grid[r-1][c]=='1'){
                v[r-1][c]=true;
                q.push({r-1,c});
            }
        }
        // bottom
        if(r+1<m){
            if(v[r+1][c]==false && grid[r+1][c]=='1'){
                v[r+1][c]=true;
                q.push({r+1,c});
            }
        }
       // left
       
       if(c>0){
          if(v[r][c-1]==false && grid[r][c-1]=='1'){
            v[r][c-1]=true;
            q.push({r,c-1});

          }
       }

       // right

       if(c+1<n){
          if(v[r][c+1]==false && grid[r][c+1]=='1'){
            v[r][c+1]=true;
            q.push({r,c+1});
            
          }
       }



    }    
   }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>v(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==false && grid[i][j]=='1'){
                    bfs(i,j,v,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
