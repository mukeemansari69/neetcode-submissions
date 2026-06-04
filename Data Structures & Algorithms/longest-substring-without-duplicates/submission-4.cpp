class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int maxlen=0;
       int n=s.size();
       for(int i=0;i<n;i++){
              unordered_set<char>st;
              int len=0;
           for(int j=i;j<n;j++){
            if(st.find(s[j])!=st.end()) break;
            st.insert(s[j]);
            len++;
           }
           maxlen=max(maxlen,len);
       } 
       return maxlen;
    }
};
