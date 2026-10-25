// https://leetcode.cn/problems/distant-barcodes/

class Solution // 定义题解类
{
public: // 公有成员区域
    vector<int> rearrangeBarcodes(vector<int>& barcodes) // 将条形码重新排列，使相邻位置的数字都不相同
    {
        unordered_map<int, int> hash; // 使用哈希表统计每一种条形码出现的次数，key 是条形码，value 是出现次数
        int maxValue = 0; // 记录出现次数最多的条形码的值
        int maxCount = 0; // 记录出现次数最多的条形码出现了多少次
        for(auto e : barcodes) // 遍历所有条形码，统计每个数字出现的次数
        {
            hash[e]++; // 当前条形码 e 出现一次，因此对应的计数加1
            if(maxCount < hash[e]) // 如果当前条形码的出现次数超过了之前记录的最大出现次数
            {
                maxCount = hash[e]; // 更新最大出现次数
                maxValue = e; // 同时记录出现次数最多的条形码
            }
        }
        int n = barcodes.size(); // 获取所有条形码的总数量
        vector<int> ret(n); // 创建结果数组，长度与原数组相同
        int index = 0; // 从下标0开始填充结果数组，优先填偶数下标
        for(int i = 0; i < maxCount; i++) // 将出现次数最多的条形码依次放入结果数组
        {
            ret[index] = maxValue; // 将出现次数最多的条形码放到当前位置
            index += 2; // 下一个位置间隔一个元素，放到下一个偶数下标，从而避免相同数字相邻
        }
        hash.erase(maxValue); // 出现次数最多的条形码已经全部放入结果数组，从哈希表中删除，后面只处理其他条形码
        for(auto& [x, y] : hash) // 遍历剩余的所有条形码，其中 x 是条形码的值，y 是它出现的次数
        {
            for(int i = 0; i < y; i++) // 按照当前条形码出现的次数，将它放入结果数组
            {
                if(index >= n) index = 1; // 如果偶数下标已经超过数组末尾，就从下标1开始填充奇数位置
                ret[index] = x; // 将当前条形码放入结果数组的指定位置
                index += 2; // 继续跳到下一个间隔位置，保证相同条形码不会连续出现
            }
        }
        return ret; // 返回重新排列后的条形码数组
    }
};