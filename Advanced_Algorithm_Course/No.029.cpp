// https://leetcode.cn/problems/subarray-sum-equals-k/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0, ret = 0;
        for (auto x : nums)
        {
            sum += x;
            if (hash.count(sum - k)) ret += hash[sum - k];
            hash[sum]++;
        }
        return ret;
    }
};
int main()
{
    Solution su;
    vector<int> nums = { 1,1,1 };
    int k = 2;
    su.subarraySum(nums, k);
    return 0;
}