class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        vector<int> prefixOne(n);

        for(int i = 0; i < n; i++){
            if(i == 0){
                if(s[i] == '1'){
                    prefixOne[i] = 1;
                }
            }else{
                prefixOne[i] = prefixOne[i-1];

                if(s[i] == '1'){
                    prefixOne[i]++;
                }
            }
        }

        vector<pair<int,int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                if(i > 0){
                    if(prefixOne[j] - prefixOne[i-1] == k){
                        ans.push_back({i,j});
                    }
                }else{
                    if(prefixOne[j] == k){
                        ans.push_back({0,j});
                    }
                }
            }
        }

        // No valid substring
        if(ans.empty()){
            return "";
        }

        string result = "";
        int mini = 1e8;
        int idx = 0;

        for(int i = 0; i < ans.size(); i++){

            int len = ans[i].second - ans[i].first + 1;

            if(mini > len){
                idx = i;
                mini = len;
            }
            else if(mini == len){

                string s1 = s.substr(ans[i].first, len);
                string s2 = s.substr(ans[idx].first, len);

                if(s1 < s2){
                    idx = i;
                }
            }
        }

        for(int i = ans[idx].first; i <= ans[idx].second; i++){
            result += s[i];
        }

        return result;
    }
};