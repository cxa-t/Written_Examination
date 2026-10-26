// https://leetcode.cn/problems/reorganize-string/


class Solution // 定义题解类
{
public: // 公有成员区域
    string reorganizeString(string s) // 将字符串重新排列，使相邻字符都不相同，如果无法做到则返回空字符串
    {
        int n = s.size(); // 获取字符串的长度
        unordered_map<char, int> hash; // 使用哈希表统计每个字符出现的次数，key 是字符，value 是出现次数
        char maxAlpha = ' '; // 记录出现次数最多的字符
        int maxCount = 0; // 记录出现次数最多的字符出现了多少次
        for(auto& e : s) // 遍历字符串中的每一个字符，统计每个字符的出现次数
        {
            hash[e]++; // 当前字符 e 出现一次，因此对应的计数加1
            if(maxCount < hash[e]) // 如果当前字符的出现次数超过了之前记录的最大出现次数
            {
                maxAlpha = e; // 更新出现次数最多的字符
                maxCount = hash[e]; // 更新最大出现次数
            }
        }
        string ret(n, ' '); // 创建长度为 n 的结果字符串，先用空格初始化每个位置
        if(maxCount > (n + 1) / 2) return ""; // 如果出现次数最多的字符超过了最多能够占据的位置数量，则无论如何都会有相邻字符相同，直接返回空字符串
        int index = 0; // 从下标0开始填充结果字符串，优先填充偶数位置
        for(int i = 0; i < maxCount; i++) // 将出现次数最多的字符依次放入结果字符串
        {
            ret[index] = maxAlpha; // 将出现次数最多的字符放到当前偶数下标位置
            index += 2; // 下一个相同字符放到下一个偶数位置，中间至少间隔一个字符
        }
        hash.erase(maxAlpha); // 出现次数最多的字符已经全部放入结果字符串，从哈希表中删除
        for(auto& [x, y] : hash) // 遍历剩余的所有字符，其中 x 是字符，y 是该字符出现的次数
        {
            for(int i = 0; i < y; i++) // 按照当前字符出现的次数，将它逐个放入结果字符串
            {
                if(index >= n) index = 1; // 如果偶数位置已经全部填满，就从下标1开始填充奇数位置
                ret[index] = x; // 将当前字符放入结果字符串的指定位置
                index += 2; // 继续移动到下一个间隔位置，尽可能保证相同字符不相邻
            }
        }
        return ret; // 返回重新排列后的字符串
    }
};