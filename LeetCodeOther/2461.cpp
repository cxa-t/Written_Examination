// https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        long long int ret = 0;
        if (nums.size() < k) return 0;

        int left = 0;
        int right = 0;
        long long int sum = 0;
        unordered_map<int, int> hash;
        while (right < nums.size())
        {
            hash[nums[right]]++;
            sum += nums[right];
            while (hash[nums[right]] > 1)
            {
                hash[nums[left]]--;
                sum -= nums[left++];
            }
            if (right - left + 1 > k)
            {
                hash[nums[left]]--;
                sum -= nums[left++];
            }
            if (right - left + 1 == k)
                ret = max(ret, sum);
            right++;
        }
        return ret;
    }
};

int main()
{
    Solution su;
    vector<int> nums = { 1,5,4,2,9,9,9 };
    int k = 3;
    su.maximumSubarraySum(nums, k);
    return 0;
}