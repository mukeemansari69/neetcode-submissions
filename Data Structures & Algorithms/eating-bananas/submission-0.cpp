class Solution {
public:
   bool check(int mid,vector<int>& piles,int h){
    int count=0;
     for(int i=0;i<piles.size();i++){
        if(piles[i]<mid) count++;
        else if(piles[i]%mid==0) count+=piles[i]/mid;
        else count+=piles[i]/mid+1;
     }
     if(count>h) return false;
     else return true;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
       int maxele=INT_MIN;
       for(int i=0;i<piles.size();i++){
          maxele=max(maxele,piles[i]);
       } 
       int ans=maxele;
       int lo=1;
       int hi=maxele;
       while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,piles,h)){
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
       }
       return ans;
    }
};
