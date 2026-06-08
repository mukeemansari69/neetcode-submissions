class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
           priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int d = x * x + y * y;

            pq.push({d, i});
        }

        while(k--) {
            int idx = pq.top().second;
            pq.pop();

            ans.push_back(points[idx]);
        }

        return ans;
             
    }
};
