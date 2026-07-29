class Solution {
    int mod = 1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       
        vector<int>prefixsum(n) ;
        for(int i= 0 ;i< n ;i++){
            if(i==0 ) prefixsum[i] = nums[i] ;
            else prefixsum[i] = prefixsum[i-1] + nums[i] ; 

        }
        vector<int>ans; 
        for(int i= 0 ; i  < n ; i++ ){
            for(int j = i; j < n ;j++){
                if( i <= 0 ){
                ans.push_back(prefixsum[j]) ; 
            }
            else{
                ans.push_back(prefixsum[j] - prefixsum[i-1]) ; 
            }
            }
            
        }
        sort(ans.begin(),ans.end()) ; 

     long long  int sum = 0 ;
       for(int i= left-1 ; i < right ; i++){
        sum+= ans[i] ; 
       }
       return sum % mod ; 
    }
};