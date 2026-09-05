class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size() ; 
        long long int cnt= 0;
        for(int i= 0 ; i < n ;i++){
             int temp = nums[i] ; 
            while(temp){
                if(temp% 10== digit)cnt++ ;
                temp/=10 ; 
            }
        }
        return cnt ; 
    }
};