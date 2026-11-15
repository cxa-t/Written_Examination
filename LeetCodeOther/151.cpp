//  https://leetcode.cn/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150

class Solution // 定义题解类，使用双指针和两次反转实现单词顺序反转
{
public:
    void ReverseWord(string& s, int start, int end) // 定义反转函数，反转字符串中[start,end]范围内的字符
    {
        while(start < end) swap(s[start++], s[end--]); // 当左右指针没有相遇时，交换两端字符，交换完成后左右指针分别向中间移动
    }
    string reverseWords(string s) // 接收一个字符串，反转其中单词的排列顺序，并返回处理后的字符串
    {
        int left = 0; // 定义左指针，指向下一个准备写入字符的位置，也表示当前处理后的字符串长度
        int right = 0; // 定义右指针，用来遍历原字符串中的每一个字符
        int n = s.size(); // 获取原字符串的长度，方便控制右指针的遍历范围
        while(right < n && s[right] == ' ') right++; // 跳过字符串开头的所有空格，让right指向第一个有效字符
        while(right < n) // 遍历整个字符串，删除单词之间多余的空格
        {
            if(s[right] != ' ' || (left > 0 && s[left - 1] != ' ')) // 如果当前字符不是空格，或者当前字符是空格但前一个已经保留的字符不是空格，就需要保留当前字符
                s[left++] = s[right++]; // 将right指向的字符复制到left位置，然后left和right分别向后移动一位
            else // 如果当前字符是空格，并且前一个已经保留的字符也是空格，说明这是多余的连续空格
                right++; // 不保留当前空格，只移动right指针，继续寻找下一个有效字符
        }
        if(left > 0 && s[left - 1] == ' ') left--; // 如果处理后的字符串最后一个字符是空格，说明末尾存在多余空格，将left向前移动一位
        s.resize(left); // 将字符串长度缩小为left，删除后面没有使用的字符，只保留有效内容
        n = left; // 更新字符串长度，因为删除多余空格后，字符串的长度已经发生变化
        int start = 0; // 定义start，记录当前需要反转的单词的起始下标
        reverse(s.begin(), s.end()); // 使用STL中的reverse函数整体反转字符串，使单词顺序和每个单词内部的字符顺序都发生反转
        for(int i = 0; i < n; i++) // 遍历整体反转后的字符串，寻找每个单词的结束位置
        {
            if(s[i] == ' ') // 如果当前位置是空格，说明前一个单词已经遍历结束
            {
                ReverseWord(s, start, i - 1); // 反转当前单词，将单词内部的字符顺序恢复
                start = i + 1; // 更新start，使其指向下一个单词的起始位置，跳过当前空格
            }
        }
        ReverseWord(s, start, n - 1); // 循环结束后，最后一个单词还没有反转，因此单独反转最后一个单词
        return s; // 返回处理完成的字符串，此时单词顺序已经反转，单词内部顺序保持不变
    }
};