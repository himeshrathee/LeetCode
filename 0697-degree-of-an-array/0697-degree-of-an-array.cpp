class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n= nums.size() ; 
        int maxi = -1e9 ; 
        unordered_map<int,int>count;
        for(auto ele : nums){
          count[ele]++; 
          maxi = max(count[ele] , maxi) ; 
        }
         vector<int>eles; 
         for(auto &[a,b]: count){
          if(b == maxi ){
            eles.push_back(a) ; 
          }
         }
         int ans = 1e9 ; 
         for(int i = 0;i<eles.size(); i++){
            int left =0 ; 
            int right = n-1; 
            while(nums[left] != eles[i]){
                left++; 
            }
             while(nums[right] != eles[i] ){
                right--; 
            }
            ans = min(right - left + 1 ,ans ); 



         } 

return ans ; 



    }
};