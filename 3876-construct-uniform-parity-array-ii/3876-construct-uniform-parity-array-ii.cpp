class Solution {
bool checkforodd(vector<int>& nums1 ,int minodd ){
    for(int i = 0 ;i< nums1.size();i++){
        if(nums1[i] % 2 == 0){
            if(nums1[i] <  minodd){
                return false ; 
            }          
        }
    }
    return true ; 
}
public:
    bool uniformArray(vector<int>& nums1) {
    int n = nums1.size() ;
    bool isodd= false ; 
    bool iseven = false;
    
    int minodd = 1e9; 
      
     for(int i = 0 ; i< n;i++){
        if(nums1[i] % 2 == 0 ){
            iseven = true ; 
        }else{
            isodd = true ; 
            minodd = min(minodd , nums1[i]) ; 
        }
     
    }
  if(isodd ==  false || iseven == false)return true ; 
   return checkforodd(nums1, minodd) ; 
    }
};