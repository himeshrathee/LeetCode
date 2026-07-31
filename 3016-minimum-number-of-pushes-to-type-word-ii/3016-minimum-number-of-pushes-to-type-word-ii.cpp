class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>freq;
        for(auto ele : word){
            freq[ele]++; 
        }
        vector<int>v; 
        for(auto &[a,b] : freq ){
            v.push_back(b) ; 
        }
       sort (v.begin() , v.end() , greater<int>()) ; 
       long long int cnt = 0 ; 
       for(int i= 0 ;i<v.size() ; i++){
       if(i<=7){
       cnt+=v[i]*1 ; 
       }else if(i<= 15){
        cnt+= v[i]*2 ; 

       }else if(i <=23){
        cnt +=v[i]*3; 
       }else{
        cnt+= v[i]*4; 
       }
       }
       return cnt; 
    }
};