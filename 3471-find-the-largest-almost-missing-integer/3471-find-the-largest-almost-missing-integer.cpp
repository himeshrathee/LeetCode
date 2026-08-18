class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n= nums.size();
        int maxi= -1e8;
       
        
        map<int,int>count; 
        for(auto ele : nums){
        count[ele]++; 
        if(ele>maxi)maxi= ele; 
        
        }
        if(k==1){
            int ans= -1;
            for(auto ele :nums){
                if(count[ele]==1 && ele>ans)ans=ele; 
            }
            return ans ; 
        }
        if(k==n)return maxi; 
        if(count[nums[0]] >1 && count[nums[n-1]]> 1)return -1 ; 
        if(count[nums[n-1]]>1  && count[nums[0]]==1 )return nums[0];
        if(count[nums[n-1]]==1  && count[nums[0]]>1 )return nums[n-1];
        if(nums[0]>nums[n-1])return nums[0];
        else return nums[n-1] ;
    }
};