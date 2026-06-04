class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i=0;i<=nums.size()-k;i++){
            priority_queue<int>pq;
            for(int j=i;j<i+k;j++){
                pq.push(nums[j]);
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};
