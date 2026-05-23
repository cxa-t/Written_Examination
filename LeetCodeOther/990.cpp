// https://leetcode.cn/problems/satisfiability-of-equality-equations/

//思路
//利用并查集 先将所有的等式的两边放在一个集合 然后判断不等式的两边是不是在一个集合，在的话就是false
//为什么不能一次进行判断，等式具有传递性，所以不能提前判断不等式
class Solution
{
public:
    bool equationsPossible(vector<string>& equations)
    {
        vector<int> ufs(26, -1);
        auto findroot = [&ufs](int x)
            {
                while (ufs[x] >= 0)
                    x = ufs[x];
                return x;
            };
        for (auto& e : equations)
        {
            if (e[1] == '=')
            {
                int root1 = findroot(e[0] - 'a');
                int root2 = findroot(e[3] - 'a');
                if (root1 != root2)
                {
                    ufs[root1] += ufs[root2];
                    ufs[root2] = root1;
                }
            }
        }
        for (auto& e : equations)
        {
            if (e[1] == '!')
            {
                int root1 = findroot(e[0] - 'a');
                int root2 = findroot(e[3] - 'a');
                if (root1 == root2)
                {
                    return false;
                }
            }
        }
        return true;
    }
};