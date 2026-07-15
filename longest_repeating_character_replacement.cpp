class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> mp;
        int res = 0, count = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            count = max(count, ++mp[s[i]]);
            if (res - count < k)
                res++;
            else
                mp[s[i - res]]--;
        }
        return res;
    }
};