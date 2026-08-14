class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size() ; 
        
        int maxi = -1e9 ; 
        int left =0 ; 
        int right = 0 ; 
         vector<char>count(26,0);
       
       while( left < n && right < n ){
         int len = 0 ; 
        if(count[ s[right] -'a' ] < 2){
            count[s[right]-'a']++; 
             len = right - left + 1 ; 
            right++ ; 
            
        }else{
        
           while(count[s[right]-'a'] >=2  ){
            count[ s[left] -'a' ]--; 
            left++; 
           }
           count[s[right]-'a']++; 
             len = right - left + 1 ; 
             right++; 
        }
        
           maxi = max(maxi,len) ;
        }
       return maxi ; 
        
    }
};