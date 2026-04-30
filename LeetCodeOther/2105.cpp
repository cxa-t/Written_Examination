// https://leetcode.cn/problems/watering-plants-ii/

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int ca = capacityA;
        int cb = capacityB;
        int left = 0;
        int right = plants.size() - 1;
        int ret = 0;
        while (left < right)
        {
            if (ca < plants[left])
            {
                ret++;
                ca = capacityA;
            }
            if (cb < plants[right])
            {
                ret++;
                cb = capacityB;
            }
            ca -= plants[left++];
            cb -= plants[right--];
        }
        if (left == right && ca < plants[left] && cb < plants[left]) ret++;
        return ret;
    }
};