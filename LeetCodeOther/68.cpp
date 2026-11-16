//  https://leetcode.cn/problems/text-justification/?envType=study-plan-v2&envId=top-interview-150


class Solution // 定义题解类，使用贪心算法和字符串模拟实现文本左右对齐
{
public: // 公有成员区域
    vector<string> fullJustify(vector<string>& words, int maxWidth) // 接收单词数组和每行最大宽度，返回排版完成的所有字符串
    {
        vector<string> ret; // 定义结果数组，用来保存每一行排版完成后的字符串
        int n = words.size(); // 获取单词数组的长度，也就是单词的总数量
        int left = 0; // 定义左指针，指向当前这一行第一个单词的下标
        while(left < n) // 只要还有单词没有处理，就继续生成下一行
        {
            // 1、使用双指针和贪心思想，计算当前行最多可以放多少个单词
            int right = left; // 定义右指针，初始指向当前行的第一个单词，用来寻找当前行最后一个单词
            int wordlength = 0; // 记录当前行所有单词的总长度，不包含单词之间的空格
            while(right < n && wordlength + words[right].size() + (right - left) <= maxWidth) // 判断当前单词能否放入当前行，其中wordlength是已有单词总长度，words[right].size()是准备加入的单词长度，right-left是加入后单词之间最少需要的空格数量
            {
                wordlength += words[right].size(); // 将当前单词的长度加入总长度，更新当前行所有单词的字符总数
                right++; // 当前单词已经成功放入当前行，右指针向后移动，继续尝试加入下一个单词
            }
            // 2、计算当前行的单词数量、总空格数量以及单词之间的间隔数量
            int wordcount = right - left; // 计算当前行包含的单词数量，因为当前行的单词下标范围是[left,right)，所以数量为right-left
            int countspace = maxWidth - wordlength; // 计算当前行需要填充的空格总数，用每行最大宽度减去所有单词的总长度
            string line; // 定义字符串line，用来拼接当前行的单词和空格
            int gaps = wordcount - 1; // 计算单词之间的间隔数量，n个单词之间一共有n-1个间隔
            // 3、判断当前行是最后一行、只有一个单词，还是普通的多个单词行
            if(wordcount == 1 || right == n) // 如果当前行只有一个单词，或者右指针已经到达数组末尾，说明当前行是特殊行，需要采用左对齐方式
            {
                for(int i = left; i < right; i++) // 遍历当前行的所有单词，注意right不包含在当前行的范围内
                {
                    line += words[i]; // 将当前单词添加到当前行字符串的末尾
                    if(i < right - 1) line += " "; // 如果当前单词不是最后一个单词，就在后面添加一个空格，保证单词之间只有一个空格
                }
                line += string(maxWidth - line.size(), ' '); // 计算当前行还差多少个字符达到maxWidth，并将剩余空格全部补充到字符串末尾
            }
            else // 如果当前行不是最后一行，并且包含多个单词，就需要将空格均匀分配到单词之间
            {
                int avg = countspace / gaps; // 计算每个单词间隔平均需要分配多少个空格，使用整数除法得到平均值
                int extra = countspace % gaps; // 计算平均分配后剩余的空格数量，这些额外空格需要从左向右依次分配
                for(int i = left; i < right; i++) // 遍历当前行的所有单词，依次将单词和对应数量的空格添加到line中
                {
                    line += words[i]; // 将当前单词添加到当前行字符串的末尾
                    if(i < right - 1) // 如果当前单词不是最后一个单词，说明后面还存在单词间隔，需要添加空格
                    {
                        if(extra > 0) // 如果还有剩余的额外空格，就优先分配给当前间隔
                        {
                            line += string(avg + 1, ' '); // 当前间隔添加avg+1个空格，因为它需要额外多分配一个空格
                            extra--; // 已经分配了一个额外空格，因此剩余的额外空格数量减1
                        }
                        else // 如果额外空格已经全部分配完毕
                        {
                            line += string(avg, ' '); // 当前间隔只添加平均分配得到的avg个空格
                        }
                    }
                }
            }
            ret.push_back(line); // 当前行已经拼接完成，将它加入结果数组，作为最终排版结果的一部分
            left = right; // 更新左指针，使其指向下一行的第一个单词，继续处理剩余单词
        }
        return ret; // 所有单词处理完成，返回包含所有排版结果的字符串数组
    }
};
