class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       // finding The Next Greater index;
       int n=nums.size();
       vector<int>ngi(n);
       vector<int>ans;
       stack<int>st;
       st.push(n-1);
       ngi[n-1]=n;
       for(int i=n-2;i>=0;i--){
        while(st.size()>0 && nums[st.top()]<=nums[i]){
            st.pop();
        }
        if(st.size()==0) ngi[i]=n;
        else ngi[i]=st.top();
        st.push(i);
       } 
       int j=0;
       for(int i=0;i<=n-k;i++){
         if(j<i) j=i;
         while(ngi[j]<i+k){
            j=ngi[j];
         }
         ans.push_back(nums[j]);
       }
       return ans;
    }
};
