class Solution {
    bool possible(vector<int>& position, int m, int mid) {
    int count = 1;
    int last = position[0];

    for(int i = 1; i < position.size(); i++) {
        if(position[i] - last >= mid) {
            count++;
            last = position[i];
        }

        if(count >= m)
            return true;
    }

    return false;
}
public:
    int maxDistance(vector<int>& position, int m) {
        int low = 1;
        sort(position.begin(), position.end()) ; 
        int high = position.back() - position.front();
        int ans = 0;

while(low <= high) {
    int mid = low + (high - low) / 2;

    if(possible(position, m, mid)) {
        ans = mid;
        low = mid + 1;       
    }
    else {
        high = mid - 1;      
    }
}
return ans ; 
    }
};