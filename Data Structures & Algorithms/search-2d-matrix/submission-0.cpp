class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        if(m.empty()|| m[0].empty()) return false;
        for(int i=0;i<m.size();i++){
            int cols=m[0].size();
            if(m[i][cols-1]<target) continue;            
                int lo=0;
                int hi=cols-1;
                while(lo<=hi){
                    int mid=lo+(hi-lo)/2;
                    if(m[i][mid]==target) return true;
                    else if(m[i][mid]<target) lo=mid+1;
                    else hi=mid-1;
                }
            
        }
        return false;
    }
};
