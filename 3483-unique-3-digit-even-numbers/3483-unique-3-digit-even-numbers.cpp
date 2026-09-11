
class Solution {
    int fact(int n){
        if(n <= 1) return 1; 
        return n * fact(n-1); 
    }

public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size(); 
        vector<int>freq(10,0);
        set<int>st;
      
        for(int i = 0; i < n; i++){
            freq[digits[i]]++; 
            if(digits[i] % 2 == 0){
                st.insert(digits[i]);  
            }
        }

        int ans = 0; 
        
        for(auto it = st.begin(); it != st.end(); it++){
            
            // choose the last digit = *it
            freq[*it]--;

            
            for(int i = 0; i < 10; i++){
                if(freq[i] == 0) continue;
                
                
                if(i == 0) continue;

                freq[i]--;

                for(int j = 0; j < 10; j++){
                    if(freq[j] > 0){
                        ans++;
                    }
                }

                freq[i]++;
            }

            freq[*it]++;
        }

        return ans;
    }
};

