class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(); 
        if(n < 2 )return n ; 
       // set<int>st; we can not use set here because it give tle its cost of operation is high then vector
       // so  a question arise in your mind  how i find max value is 2048 becauses max nums[i] <=1500 it has 11 bits in binary 
       // pow(2,10)=1024 < 1500  < pow(2,11) = 2048 ,hence max xor value is 2048  
       vector<bool>pair(2048,false) ;       
        for(int i= 0;i<n;i++ ){
          for(int j= 0 ;j < n;j++ ){
            pair[nums[i]^nums[j]] = true ;   
              }
                 }

       vector<bool>ans(2048,false); 
     for (int x = 0; x < 2048; x++) {
    if (!pair[x]) continue;

    for (int i = 0; i < n; i++) {
        ans[x ^ nums[i]] = true;
    }
}
        int cnt= 0 ; 
        for(auto ele: ans){
            if(ele==true)cnt++; 
        }
     
      return cnt ; 
    }
};