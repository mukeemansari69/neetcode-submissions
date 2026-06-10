class Solution {
public:
     int solve(int val1 ,int val2, string ch){
        if(ch=="+") return val1+val2;
        else if(ch=="-") return val1-val2;
        else if(ch=="/") return val1/val2;
       else return val1*val2;
     }
    int evalRPN(vector<string>& s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!="+" and s[i]!="*" and s[i]!="/" and s[i]!="-" ){
                int val=stoi(s[i]);
                st.push(val);
            }else{
                int val2=st.top();
                st.pop();
                int val1=st.top();
                st.pop();
                int cal=solve(val1,val2,s[i]);
                st.push(cal);

            }
        }
        return st.top();
    }
};
