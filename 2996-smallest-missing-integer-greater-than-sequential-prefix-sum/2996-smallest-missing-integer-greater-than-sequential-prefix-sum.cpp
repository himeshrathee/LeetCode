class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        set<int> st(nums.begin(), nums.end());

        long long sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        int ans = sum;

        while (st.find(ans) != st.end()) {
            ans++;
        }

        return ans;
    }
};