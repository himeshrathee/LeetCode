class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1e3)return 0 ; 
        if(n < 1e6) return  n -1e3+1 ; 
        if(n < 1e9)return   (n - 1e6 )*2 + 1e6-1e3 + 2; 
        if(n < 1e12) return (n-1e9 )*3 + (1e9-1e6 )*2 + 1e6-1e3 + 3; 
        if(n < 1e15) return (n-1e12 )*4 + (1e12 - 1e9)*3 +( 1e9-1e6)*2 + 1e6-1e3 + 4  ; 
        return (n-1e15)*5 + (1e15 - 1e12 )*4 + (1e12 - 1e9  )*3 +( 1e9-1e6 )*2 + 1e6-1e3 + 5;
    }
};