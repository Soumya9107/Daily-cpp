class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int ans = INT_MAX;
        for(int i = 0;i < nums.size();i++){
            auto &v = pos[nums[i]];

            if(v.size() >= 2){
                ans = min(ans, 2 * (i - v[0]));
                v.erase(v.begin());
            }
            v.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};