class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n =  nums.size() ;
        vector<int>arr1; 
        arr1.push_back(nums[0]) ; 
        vector<int>arr2; 
        arr2.push_back(nums[1] ) ;
        int i = 2 ; 
        while(i < n){
       if(arr1.back() > arr2.back() ){
        arr1.push_back(nums[i]) ; 
       }else{
        arr2.push_back(nums[i]) ; 
       }
       i++; 
        }
        for(int i = 0 ;i< arr1.size();i++){
            nums[i] = arr1[i] ; 
        }
         for(int i = 0 ;i< arr2.size();i++){
            nums[i + arr1.size()] = arr2[i] ; 
        }
        return nums ; 
    }
};