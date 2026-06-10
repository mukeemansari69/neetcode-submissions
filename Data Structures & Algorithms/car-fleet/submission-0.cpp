class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        vector<pair<int ,double>>car;
        for(int i=0;i<p.size();i++){
            double time=(double)(t-p[i])/s[i];
            car.push_back({p[i],time});
        }
        sort(car.begin(),car.end());
        stack<double>st;
        for(int i=car.size()-1;i>=0;i--){
            double time=car[i].second;
            while( st.size()==0|| time>st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
