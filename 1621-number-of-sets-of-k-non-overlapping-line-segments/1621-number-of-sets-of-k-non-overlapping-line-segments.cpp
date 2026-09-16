class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        vector<long long> dp(k + 1, 0);
        vector<long long> pref(k + 1, 0);

        dp[0] = 1;
        pref[0] = 1;

        for(int i = 1;i < n;i++){
            vector<long long> ndp(k + 1, 0);
            ndp[0] = 1;

            for(int j = 1;j <= k;j++){
                ndp[j] = (dp[j] + pref[j - 1]) % MOD;
            }
            dp = ndp;
            //sum[0] = dp[0];
            for(int j = 0;j <= k;j++){
                pref[j] = (pref[j] + dp[j]) % MOD;
            }
        }
        return dp[k];

    }
};