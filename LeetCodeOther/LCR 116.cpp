// https://leetcode.cn/problems/bLyHh0/


//思路
//利用并查集 将相连的城市放在一个集合中，最后求出集合的数量即可
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<int> ufs(n, -1);
        auto findroot = [&ufs](int x)
            {
                while (ufs[x] > 0)
                    x = ufs[x];
                return x;
            };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    int root1 = findroot(i);
                    int root2 = findroot(j);
                    if (root1 != root2)
                    {
                        ufs[root1] += ufs[root2];
                        ufs[root2] = root1;
                    }
                }
            }
        }

        int ret = 0;
        for (auto e : ufs)
            if (e < 0)
                ret++;

        return ret;
    }
};