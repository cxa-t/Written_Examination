// https://leetcode.cn/problems/trapping-rain-water/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        vector<int> lm(height.size(), 0);
        lm[0] = height[0];
        vector<int> rm(height.size(), 0);
        rm[height.size() - 1] = height[height.size() - 1];

        //当前位置左边最高的值（包括自己）
        for (int i = 1; i < height.size(); i++)
            lm[i] = max(lm[i - 1], height[i]);
        //当前位置右边最高的值（包括自己）
        for (int i = height.size() - 2; i >= 0; i--)
            rm[i] = max(rm[i + 1], height[i]);
        //遍历每一个位置，以左右边界最低的计算，减去自己占的格数
        int ret = 0;
        for (int i = 0; i < height.size(); i++)
            ret += min(lm[i], rm[i]) - height[i];

        return ret;
    }
};

int main()
{
    Solution su;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    su.trap(height);
	return 0;
}