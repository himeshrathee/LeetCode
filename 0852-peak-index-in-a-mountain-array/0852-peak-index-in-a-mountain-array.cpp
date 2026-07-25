class Solution {
    int f( int left ,int right ,vector<int>&arr){
        
        while(left < right){
            int mid= left + (right - left ) /2 ;
            if(arr[mid+1] > arr[mid]){
                left = mid+1   ; 
            }else{
             right = mid ; 
            }
        }
        return left ; 
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0 ;
        int right = n-1 ;
        return f(left,right,arr) ; 
    }
};