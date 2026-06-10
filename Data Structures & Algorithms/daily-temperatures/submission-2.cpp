class Solution {
public:
     
    vector<int> dailyTemperatures(vector<int>& arr) {
         int n=arr.size();
        stack<int>st;
        vector<int>pgi(n);
        pgi[n-1]=0;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()==0) pgi[i]=0;
            else pgi[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int diff=pgi[i]-i;
            if(diff<0){
                pgi[i]=0;
            }else{
                pgi[i]=diff;
            }
        }
        return pgi;
    }
};
