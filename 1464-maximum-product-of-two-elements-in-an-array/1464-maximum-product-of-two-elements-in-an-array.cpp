class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        int maxi = -1e9 ;
        
        for(int i= 0 ; i < n-1;i++){
            for(int j=i+1;j<n;j++){
                maxi= max(maxi , (nums[i]-1 )* (nums[j]-1) ) ; 
            }
        }
        return maxi; 
    }
};