class Solution {
public:
bool f(int a,int b ,  int left ,int right , vector<int>&nums ,bool flag){
    if(left> right) return a >= b; 
    if(left == right){
        if ( flag)return a + nums[left] >= b  ; 
        else return a >= nums[left] + b; 
          
    }
     if(flag ==  true ){
      bool takeleft =  f( a+nums[left],b ,left+1 , right,nums,false) ; 
      bool takeright =  f(a+ nums[right],b ,left , right-1 , nums ,false ) ; 
        return takeleft || takeright ; 
     }
        bool takeleft =  f( a ,b+ nums[left] ,left+1 , right,nums,true) ; 
        bool takeright =  f(a,b + nums[right] ,left , right-1 , nums ,true ) ; 
        return takeleft && takeright  ; 
          
      
}
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size() ;
        return f( 0,0, 0,n-1, nums, true ) ; 
    }
};