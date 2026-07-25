class Solution {
public:
    int maxProduct(int n){
        int temp = n; 
        string digits= to_string(n) ; 
        map<int,int>freq; 
      for(auto ele : digits){
        if(freq[ele-'0'] < 2){
         freq[ele-'0']++ ;     
        }
      }
       vector<int>ans; 
       int i=9 ; 
       while(i>=0 && ans.size()< 2){
         if(freq.find(i)!= freq.end() && freq[i] >  0 ){
          ans.push_back(i) ; 
          freq[i]--;  
         }else{
            i--; 
         }
       }
       return ans[0]*ans[1] ; 

    }
};