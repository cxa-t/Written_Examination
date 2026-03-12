#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/3sum/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), less<int>());
        vector<vector<int>> ret;
        //不足三元组的情况
        if (nums.size() < 3) return ret;
        int i = nums.size() - 1;
        //只需要处理比三个元素多的vector
        while (i > 1)//0 1 2 3 4 5 
        {
            int left = 0,right = i - 1;
            
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum + nums[i] == 0)
                {
                    ret.push_back({ nums[left],nums[right],nums[i] });
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum + nums[i] > 0)
                    right--;
                else
                    left++;
            }

            while (i > 1 && nums[i] == nums[i - 1])
                i--;
            i--;
        }
        return ret;
    }
};
int main()
{
    Solution su;
    vector<int> nums = { 0,0,0 };
    su.threeSum(nums);
    return 0;
}