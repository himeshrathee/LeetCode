class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> count ; 
        vector<int>temp= nums ; 
        sort(nums.begin(),nums.end()) ;
        int i= 0 ;  
        for(auto ele : nums){
            if(count.find(ele)==count.end()){
                count[ele] = i ; 
            }
            
            i++; 
        }
        vector<int>ans ; 
      for(auto ele: temp){
      ans.push_back(count[ele]) ; 
      }
      return ans  ;
    }
};