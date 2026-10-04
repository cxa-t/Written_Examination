// https://leetcode.cn/problems/sort-the-people/

class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) // 根据身高从高到低对人员姓名进行排序
    {
        int n = heights.size(); // 获取人数
        vector<int> index(n); // 创建下标数组，用来记录每个人原来的位置
        for (int i = 0; i < n; i++) index[i] = i; // 初始化下标数组，使 index[i] = i
        sort(index.begin(), index.end(), [&](int i, int j) { return heights[i] > heights[j]; }); // 根据对应的身高对下标进行排序，身高较高的人对应的下标排在前面
        vector<string> ret(n); // 创建结果数组，用来保存按照身高降序排列后的姓名
        for (int i = 0; i < n; i++) // 遍历排序后的下标数组
        {
            ret[i] = names[index[i]]; // 根据排序后的下标找到对应姓名，并存入结果数组
        }
        return ret; // 返回按照身高从高到低排列后的姓名数组
    }
};