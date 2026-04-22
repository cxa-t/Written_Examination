// https://leetcode.cn/problems/subarray-sums-divisible-by-k/

class Solution 
{
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;
        hash[0 % k]++;
        int sum = 0;
        int ret = 0;
        for (auto e : nums)
        {
            sum += e;
            int r = (sum % k + k) % k;
            if (hash.count(r)) ret += hash[r];
            hash[r]++;
        }
        return ret;
    }
};