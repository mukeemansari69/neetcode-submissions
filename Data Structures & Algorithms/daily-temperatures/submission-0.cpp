class Solution {
public:
     
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        int n=t.size();
        st.push(n-1);
        vector<int>ans(n);
        ans[n-1]=0;
       for(int i=n-2;i>=0;i--){
       
          while(st.size()>0 and t[st.top()]<=t[i]){
            st.pop();
          }
          if(st.size()!=0) ans[i]=st.top()-i;
          
          st.push(i);
       }
    return ans;
    }
};
