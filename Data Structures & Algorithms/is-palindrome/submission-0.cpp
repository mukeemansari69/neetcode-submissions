class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isalnum(c)){
                t+=tolower(c);
            }
        }
        int i=0,j=t.size()-1;
        while(i<j){
            if(t[i]!=t[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
