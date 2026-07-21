class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n= s.size() ; 
        if(n==1)return s[0]-'0'; 
        vector<string>v; 
        string result=""; 
        result+= s[0] ;

        for(int i = 1; i<n ;i++ ){
          if(s[i]==s[i-1]){
            result+= s[i] ; 
            
          }else{
            v.push_back(result) ; 
            result="";
            result+=s[i] ;
            
          }
        }
        v.push_back(result ) ; 

        int totalOne = 0;
for (auto &x : v) {
    if (x[0] == '1')
        totalOne += x.size();
}
int ans = totalOne;

        if(v.size()==1 && v[0][0]=='1'){
            return v[0].size() ; 
        }else if( v.size()==1 && v[0][0]=='0'){
            return 0; 
        }
        if(v.size() < 3 ){
            if(v[0][0]=='1'){
                return v[0].size() ; 
            }else{
              return  v[1].size() ;
            }
        }
       

     for (int i = 1; i < v.size() - 1; i++) {
    if (v[i][0] == '1' &&
        v[i - 1][0] == '0' &&
        v[i + 1][0] == '0') {

        int gain = v[i - 1].size() + v[i + 1].size();
        ans = max(ans, totalOne + gain);
    }
}
return ans;

    }
};