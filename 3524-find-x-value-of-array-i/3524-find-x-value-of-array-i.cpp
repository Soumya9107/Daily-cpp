class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0);
        vector<long long> dp(k, 0);
        for(int x : nums){
            vector<long long> ndp(k, 0);
            int val = x % k;
            ndp[val]++;
            for(int r = 0;r < k;r++){
                if(dp[r] > 0){
                    int nr = (long long)r * val % k;
                    ndp[nr] += dp[r];
                }
            }
            for(int r = 0;r < k;r++){
                ans[r] += ndp[r];
            }
            dp.swap(ndp);
        }
        return ans;
    }
};