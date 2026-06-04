class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mxprofit=0;
        for(int i=0;i<p.size()-1;i++){
            for(int j=i+1;j<p.size();j++){
                mxprofit=max(mxprofit,p[j]-p[i]);
            }
        }
        return mxprofit;
    }
};
