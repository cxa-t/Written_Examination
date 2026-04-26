// https://leetcode.cn/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
        vector<vector<int>> ret(image);
        for (int i = 0; i < ret.size(); i++)
        {
            int left = 0;
            int right = ret[i].size() - 1;
            while (left < right)
            {
                if (ret[i][left] == 0) ret[i][left] = 1;
                else ret[i][left] = 0;
                if (ret[i][right] == 0) ret[i][right] = 1;
                else ret[i][right] = 0;
                std::swap(ret[i][left++], ret[i][right--]);
            }
            if (left == right)
            {
                if (ret[i][left] == 0) ret[i][left] = 1;
                else ret[i][left] = 0;
            }
        }
        return ret;
    }
};