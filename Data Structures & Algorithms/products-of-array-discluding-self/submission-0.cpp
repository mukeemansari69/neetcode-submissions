class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>post(n);

         pre[0]=1;
         post[n-1]=1;
         int p=nums[0];
        for(int i=1;i<nums.size();i++){
         pre[i]=p;
            p=p*nums[i];
        }
        p=1;
         p=nums[n-1];
        for(int i=n-2;i>=0;i--){
           post[i]=p;
            p=p*nums[i];
        }
        for(int i=0;i<pre.size();i++){
            cout<<post[i]<<" ";
        }
        vector<int>res;
        for(int i=0;i<pre.size();i++){
            res.push_back(pre[i]*post[i]);
        }
        return res;
    }
};
