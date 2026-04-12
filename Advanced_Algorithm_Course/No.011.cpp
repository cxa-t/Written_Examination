// https://leetcode.cn/problems/max-consecutive-ones-iii/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int left = 0;
        int right = 0;
        int ret = INT_MIN;
        int count = k;
        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                count--;
            }

            while (count < 0)
            {
                if (nums[left++] == 0) count++;
            }
            ret = max(right - left + 1, ret);
            right++;
        }
        return ret;
    }
};

int main()
{
    Solution su;
    vector<int> v({ 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 });
    int k = 2;
    su.longestOnes(v, k);
    return 0;
}