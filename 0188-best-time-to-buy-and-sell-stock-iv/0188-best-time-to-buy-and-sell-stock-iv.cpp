class Solution {
    int f( int idx ,int transNo ,  vector<int>&prices , int n , int k, vector<vector<int>>&dp ){
        if(idx == n || transNo == 2*k)return 0; 
        if(dp[idx][transNo]!=-1)return dp[idx][transNo] ; 
        if(transNo % 2 == 0 ) { // buy 
          return dp[idx][transNo] =   max(-prices[idx]  + f(idx+1,transNo +1 , prices , n ,  k,dp ) , 0 + f(idx+1 , transNo , prices , n ,  k, dp )) ; 
        }
        return  dp[idx][transNo] =    max(prices[idx]  + f(idx+1 , transNo + 1 , prices ,  n ,  k, dp) , 0 + f(idx+1 ,transNo ,prices,  n , k,dp)) ; 
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ; 
        vector<vector<int>>dp(n,vector<int>(2*k, - 1)) ; 
        
        return  f( 0 , 0, prices, n , k,dp) ; 

    }
};