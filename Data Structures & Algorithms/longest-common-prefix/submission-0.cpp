class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(),strs.end());
       string last =strs[strs.size()-1];
       string first=strs[0];
       int i=0;
       int len=min(last.size(),first.size());
       while(i<len){
        if(first[i]==last[i]) i++;
        else break;
       } 
       return first.substr(0,i);
    }
};