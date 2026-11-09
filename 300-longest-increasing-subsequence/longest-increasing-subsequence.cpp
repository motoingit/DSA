class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 1;
        for(int out = 1; out < n; out++){ // 1 or 0 no maater
            for(int in = 0; in < out; in++)
                if(nums[in] < nums[out])
                    if(dp[in]+1 > dp[out])
                        dp[out] = dp[in]+1;
            ans = max(dp[out], ans);
        }
        return ans;
    }
};