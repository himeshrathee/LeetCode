class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n= arr1.size() ;
        int m = arr2.size() ;
        unordered_map<int,int> count ; 
        for(auto ele : arr1){
            count[ele]++ ; 
        }
        vector<int>ans ; 
        for(auto ele: arr2){
            while(count[ele]){
              ans.push_back(ele) ; 
              count[ele]-- ; 
            }
        }
        for(auto &[a,b] : count){
          while(b >  0 ){
            ans.push_back(a) ; 
            b-- ; 
        }
        }
        return ans ; 
    }
};