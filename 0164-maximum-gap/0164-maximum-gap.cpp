class Solution {
    vector<int> bucketsort(vector<int>&nums){
        int n  =nums.size() ; 
        vector<vector<int>>bucketsort(n ,vector<int>()) ; 
        float mini = 1e9 ; 
        float maxi = -1e9 ; 
        for(auto ele :nums ){
            if( maxi < ele){
                maxi = ele ; 
            }
            if( mini >  ele){
                mini = ele ; 
            }
        }if(maxi == mini)return {0}; 
        float range =( maxi - mini ) / n ; 
        
        for(int i = 0 ;i< n; i++){
            int index  = (nums[i] - mini) / range ;
            if(index >= n ){
                index-=1 ;
            } 
            float  diff = (nums[i] - mini)/range - index ; 
            if(diff == 0 && nums[i] != mini){
                bucketsort[index-1].push_back(nums[i]) ; 
            }else{
                bucketsort[index].push_back(nums[i]) ; 
            }
        }
        for(int i = 0 ;i < n ; i++){
            if(bucketsort[i].size() > 0 ){
                sort(bucketsort[i].begin() , bucketsort[i].end()) ; 
            }
        }
        vector<int>ans ; 
        for(int i = 0 ;i<n;i++){
            for(int j =0 ;j<bucketsort[i].size() ; j++){
                ans.push_back(bucketsort[i][j]) ; 
            }
        }
        return ans  ; 
    }
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size() ; 
        if(n < 2)return 0; 
       vector<int>ans = bucketsort(nums) ;
       if(ans.size() < 2)return 0 ;  
       int diff = -1e9 ; 
       for(int i = 0 ;i<n-1  ;i++){
        diff = max(diff , abs(ans[i] - ans[i+1] )  ) ; 
       }
       return diff ;
    }
};