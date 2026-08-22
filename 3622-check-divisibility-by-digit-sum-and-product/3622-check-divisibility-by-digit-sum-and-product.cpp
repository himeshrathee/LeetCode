
 #define ll long long 
class Solution {
    
public:
    bool checkDivisibility(int n) {
        int temp = n; 
        ll sum = 0 ;
        ll pr = 1 ; 
        while(temp){
            sum+= temp % 10 ; 
            pr *= temp%10 ; 
            temp/= 10 ; 
        }
        return (n % (sum + pr ) == 0 ) ;
    }
};