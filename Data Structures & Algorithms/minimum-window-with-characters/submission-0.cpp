class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        int l=0;
        int start=0;
        int minlen=INT_MAX;
        for(char ch :t){
            freq[ch]++;
        }
        int req=t.size();
        for(int i=0;i<s.size();i++){
            if(freq[s[i]]>0) req--;
            freq[s[i]]--;
            while(req==0){
                if(i-l+1<minlen){
                    minlen=i-l+1;
                    start=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) req++;
                l++;
            }
        }
        if(minlen==INT_MAX) return "";
        return s.substr(start,minlen);
    }
};
