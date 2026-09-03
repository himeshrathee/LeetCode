class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // it is so simple to if i use stl but prefer to solve  this by  count sort
        unordered_map<int,int>count ; 
        for(auto ele: heights){
            count[ele]++  ; 
        }vector<int>ans ; 
        for(int i= 1 ; i<= 100 ;i++){
            while(count[i]){
            ans.push_back(i) ; 
            count[i]-- ; 
            }
        }
        int cnt = 0 ; 
        for(int i = 0 ;i< ans.size() ;i++){
            if(ans[i] != heights[i]){
                cnt++ ; 
            }
        }
        return cnt ; 
    }
};