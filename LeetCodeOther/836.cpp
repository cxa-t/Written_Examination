// https://leetcode.cn/problems/rectangle-overlap/

class Solution {
public:
    // 判断两个矩形是否有面积重叠
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 如果某个矩形宽度或高度为 0，说明它不是有效矩形，不能产生重叠面积
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            return false;
        }

        // 判断两个矩形是否不存在重叠
        return !(rec1[2] <= rec2[0] ||   // rec1 的右边界 <= rec2 的左边界，说明 rec1 在 rec2 左边
            rec1[3] <= rec2[1] ||   // rec1 的上边界 <= rec2 的下边界，说明 rec1 在 rec2 下边
            rec1[0] >= rec2[2] ||   // rec1 的左边界 >= rec2 的右边界，说明 rec1 在 rec2 右边
            rec1[1] >= rec2[3]);    // rec1 的下边界 >= rec2 的上边界，说明 rec1 在 rec2 上边
    }
};