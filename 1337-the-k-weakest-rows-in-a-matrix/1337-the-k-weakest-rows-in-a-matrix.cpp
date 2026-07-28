class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        vector<pair<int,int>>v;
        int n = mat.size();
        for(int i= 0 ;i < n ;i++ ){
         int cnt  = 0 ; 
        for(auto ele : mat[i]){
         if(ele==1)cnt++ ;
        }
        v.push_back({cnt, i}) ; 
        }
        sort(v.begin(),v.end(),[]( const pair<int,int>&a , const pair<int,int> &b){
        if(a.first==b.first )return a.second < b.second ; 
        else return a.first <  b.first  ; 

        }) ; 
        vector<int>ans; 
        for(int i= 0; i < k;i++){
        ans.push_back(v[i].second ) ; 
        }
        return ans ; 
    }
};