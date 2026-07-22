class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        set<int> s1,s2 ;
         vector<int>ans(2) ;
         int alicesum= 0 ; 
         for( auto ele: aliceSizes){
            s1.insert(ele); 
            alicesum+= ele ; 
         }
         int bobsum= 0 ; 
           for( auto ele: bobSizes){
            s2.insert(ele); 
            bobsum += ele; 
         }
         int diff =( alicesum - bobsum )/2 ; 
         for( auto ele: aliceSizes){
            if(s2.find(ele - diff)!=s2.end() ) {
                ans[0]= ele; 
                ans[1] = ele - diff ; 
            }
         }
         return ans ; 
    }
};