class Solution {
    bool forodd(vector<int>& nums1){
    int n = nums1.size() ; 
    bool flag= false   ; 
    for(int i = 0;i<n;i++){
        if(nums1[i] % 2 !=  0 ){
            flag = true  ; 
        }
    }
    return flag ; 
    }
     bool foreven(vector<int>& nums1){
    int n = nums1.size() ; 
   
    int countodd = 0 ; 
    for(int i = 0;i<n;i++){
        if(nums1[i] % 2 !=  0 ){
            countodd++; 
        }
    }

    return (countodd % 2==0 ) ; 
    }
public:
    bool uniformArray(vector<int>& nums1) {
       return forodd(nums1) || foreven(nums1) ; 
    }
};