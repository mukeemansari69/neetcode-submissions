class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : nums) {
            pq.push(x);
        }

        int t = pq.top();
        pq.pop();

        int count = 1;
        int ans = 1;

        while(!pq.empty()) {

            int x = pq.top();
            pq.pop();

            if(x == t) {
                continue;          // duplicate ignore
            }
            else if(x == t + 1) {
                count++;
            }
            else {
                ans = max(ans, count);
                count = 1;
            }

            t = x;
        }

        ans = max(ans, count);

        return ans;
    }
};
