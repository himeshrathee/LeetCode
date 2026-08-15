class Solution {
public:
 int f( int idx,vector<int>&dp){
      if(idx==0)return 0; 
      if(idx==1)return 1; 
      if(idx==2)return 1; 
      if(dp[idx]!=-1)return dp[idx] ; 
      return  dp[idx] = f(idx-1,dp) + f(idx-2,dp) + f(idx-3,dp) ;
    }
    int tribonacci(int n) {
    vector<int>dp(n+1,-1);  
     return f(n,dp);    
    }
};