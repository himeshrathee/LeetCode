class Solution {
    int find (int n ){
        int left = 1; 
        int right = 17;
        while(left<= right){
            int mid = left + (right -left)/2 ;
             if((1LL << mid) <=  n &&  (1LL  << (mid+1)) >  n){
                return (1 << mid+1)  ; 
             }else if( (1 << mid ) > n ){
                right= mid -1 ; 
             }else{
                left = mid + 1; 
             }
        }
        return -1 ; 
    }
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        set<int>st; 
        if(n==3){
            for(auto ele : nums){
                st.insert(ele) ; 
            }
        }
        int ans= n; 
        if(n==3 &&  st.find(nums[0]^nums[1] ^ nums[2])==st.end() ){
            ans++; 
        }
        if(n<=3 )return ans; 
        else return find(n); 
        //find between which range n lies ,for ex  if n =5 .it lies between pow(2,2) and pow(2,3) . and ans is pow(2,3) -2 ; 

    }
};