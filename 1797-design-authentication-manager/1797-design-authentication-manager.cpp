class AuthenticationManager {
    int lifetime ;
    string  tokenId; 
    
    unordered_map<string,int>mp ; 
public:


    AuthenticationManager(int timeToLive) {
        
        lifetime= timeToLive ; 
    }
    
    void generate(string tokenId, int currentTime) {
        
        this->tokenId= tokenId; 
        
       mp[tokenId]= currentTime ;  
      return ; 
    }
    
    void renew(string tokenId, int currentTime) {
        if( mp.find(tokenId) != mp.end() ){
          if( currentTime <  mp[tokenId] + lifetime){
             mp[tokenId] = currentTime;  
        }

        }else{
            return ; 
        }
       
    } 
    
    int countUnexpiredTokens(int currentTime){
        int cnt = 0 ; 
        for( auto it: mp ){
            if(currentTime >=  it.second  &&  currentTime < it.second + lifetime ){
           cnt++; 
        }
        }
        return cnt; 
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */