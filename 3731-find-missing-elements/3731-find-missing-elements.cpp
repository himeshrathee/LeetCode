class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>mp ; 
        sort(nums.begin() , nums.end( )) ; 
        int  l = nums[0] ; 
        int  r= nums[nums.size()-1] ; 
        for(int i = l ; i <=r ;i++ ){
            mp[i]++ ; 
        }
         vector<int>ans  ; 
        for(auto ele : nums ){
            mp[ele]-- ; 
        }
        for( auto m : mp){
            if(m.second > 0 ){
                ans.push_back(m.first) ; 
            }
        }
       sort(ans.begin() , ans.end()) ; 
       return ans; 
    }
};