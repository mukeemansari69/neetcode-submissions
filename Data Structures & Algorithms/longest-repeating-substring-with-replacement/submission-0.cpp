class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>f(26,0);
        int l=0;
        int maxf=0;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            f[s[i]-'A']++;
            maxf=max(maxf,f[s[i]-'A']);
            while((i-l+1)-maxf>k){
                f[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
    }
};
