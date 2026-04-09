class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> case1(nums.begin(), nums.end() - 1);
        vector<int> case2(nums.begin() + 1, nums.end());

        return max(solve(case1), solve(case2));
    }
private:
    int solve(vector<int> &nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            int pick = dp[i - 2] + nums[i];
            int skip = dp[i - 1];

            dp[i] = max(pick, skip);
        }
        return dp[n - 1];
    }
};