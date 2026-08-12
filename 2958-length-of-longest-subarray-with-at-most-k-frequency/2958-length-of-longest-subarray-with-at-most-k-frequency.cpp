class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> v;

        int left = 0;
        int right = 0;
        int maxlen = 0;

        while (right < n) {
            int ele = nums[right];

            v[ele]++;
            
            while (v[ele] > k) {
                v[nums[left]]--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
            right++;
        }

        return maxlen;
    }
};