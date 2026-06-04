class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int water=0;
       vector<int>next(n); 
       vector<int>pre(n);
       int mx=h[0];
       next[0]=0;
       for(int i=1;i<n;i++){
          next[i]=mx;
          if(mx<h[i]){
            mx=h[i];
          }
       }
       mx=h[n-1];
      for(int i=n-2;i>=0;i--){
          pre[i]=mx;
          if(mx<h[i]){
            mx=h[i];
          }
       }
      for(int i=0;i<n;i++){
        pre[i]=min(pre[i],next[i]);
      }
      for(int i=0;i<n;i++){
        if(h[i]<pre[i]){
            water+=pre[i]-h[i];
        }
      }
      return water;
    }
};
