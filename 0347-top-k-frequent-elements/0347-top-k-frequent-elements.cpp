class Solution { 
public: 
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        map<int,int> count;  
        
        for(auto ele : nums){ 
            count[ele]++;  
        } 
        
        vector<pair<int,int>> v;
        
        for(auto ele : count){
            v.push_back({ele.second, ele.first});
        }
        
        sort(v.rbegin(), v.rend());
        
        vector<int> ans(k); 
        int i = 0; 
 
        for(auto ele : v){ 
            ans[i] = ele.second;  
            i++; 
            
            if(i == k){ 
                break;  
            } 
        } 
        
        return ans; 
    } 
};