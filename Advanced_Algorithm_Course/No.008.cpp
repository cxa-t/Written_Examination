#define _CRT_SECURE_NO_WARNINGS 1

//  https://leetcode.cn/problems/4sum/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());//升序
        int n = nums.size() - 1;
        if (n + 1 < 4) return ret;
        for (int i = n; i >= 3; i--)
        {
            //三数之和
            for (int j = i - 1; j >= 2; j--)
            {
                int left = 0, right = j - 1;
                while (left < right)
                {
                    long long int sum = (long long)target - nums[left] - nums[right] - nums[i] - nums[j];
                    if (sum == 0)
                    {
                        ret.push_back({ nums[left],nums[right],nums[j],nums[i] });
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                    else if (sum < 0) right--;
                    else left++;
                }
                while (j >= 2 && nums[j] == nums[j - 1]) j--;
            }
            while (i >= 3 && nums[i] == nums[i - 1]) i--;
        }
        return ret;
    }
};

int main()
{
    Solution su;
    vector<int> nums = { 1,0,-1,0,-2,2 };
    su.fourSum(nums,0);
    return 0;
}