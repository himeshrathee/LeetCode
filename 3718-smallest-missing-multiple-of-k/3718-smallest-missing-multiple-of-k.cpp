class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n  = nums.size() ; 
        set<int>st ; 
        for(auto ele : nums){
            st.insert(ele) ; 
        }
         int val = 0 ; 
         for(int i = k ; i<= k*100 ;i+= k ){
            if(st.find(i) == st.end()){
                return i ; 
            }
            val = i ; 
         }
         return val+k  ; 
    }
};