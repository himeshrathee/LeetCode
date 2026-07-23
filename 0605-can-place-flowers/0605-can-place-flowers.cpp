class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n){
       int  m = v.size();
       if(n==0 )return true ; 
      if(m== 1 && n==1 && v[0]== 0)return true ; 
      else if (m==1 && n==1 )return false;
       int cnt = 0 ; 
       for(int i= 0;i< m-1 ;i++ ){
       if(v[i]==0  ){
         if (v[i+1]== 0 && i== 0  ){
            v[i]=1; 
            cnt++ ; 
         }else if(v[i+1]==0 && v[i-1]== 0 ){
            v[i]=1 ;
            cnt++; 
         }
       }else{
        i++;
       }
       }
       if(v[m-1]==0 && v[m-2]== 0  ){
        cnt++ ; 
       }
       if(cnt<n)return false; 
       return true ; 
    }
};