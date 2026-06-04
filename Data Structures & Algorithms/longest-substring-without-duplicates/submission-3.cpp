class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int mxlen = 0;

        for(int i = 0; i < s.size(); i++) {

            unordered_set<char> st;
            int len = 0;

            for(int j = i; j < s.size(); j++) {

                if(st.find(s[j]) != st.end())
                    break;

                st.insert(s[j]);
                len++;
            }

            mxlen = max(mxlen, len);
        }

        return mxlen;
    }
};
