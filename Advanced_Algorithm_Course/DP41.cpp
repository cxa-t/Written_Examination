// https://www.nowcoder.com/practice/fd55637d3f24484e96dad9e992d3f62e?tpId=230&tqId=2032484&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196


#include <iostream>                                      // 引入标准输入输出库
#include <vector>                                        // 引入动态数组容器
using namespace std;                                     // 使用标准命名空间
int main()                                               // 程序入口函数
{
    int n, V;                                            // n表示物品数量，V表示背包容量
    cin >> n >> V;                                       // 输入物品数量和背包容量
    vector<int> v(n + 1);                                // 保存每个物品的体积
    vector<int> w(n + 1);                                // 保存每个物品的价值
    for (int i = 1; i <= n; i++)                         // 依次输入每个物品的信息
        cin >> v[i] >> w[i];                             // 输入第i个物品的体积和价值
    vector<vector<int>> dp(n + 1, vector<int>(V + 1));    // dp[i][j]表示前i个物品容量不超过j的最大价值
    for (int i = 1; i <= n; i++)                         // 依次考虑每一个物品
    {
        for (int j = 1; j <= V; j++)                     // 枚举当前背包容量
        {
            dp[i][j] = dp[i - 1][j];                      // 不选择第i个物品时继承上一层结果
            if (j >= v[i])                                 // 当前容量能够装下第i个物品
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]); // 比较选与不选第i个物品的最大价值
        }
    }
    cout << dp[n][V] << endl;                           // 输出容量不超过V时的最大价值
    dp.resize(n + 1, vector<int>(V + 1, 0));                // 重新初始化dp用于恰好装满背包的问题
    for (int j = 1; j <= V; j++) dp[0][j] = -1;         // 没有物品时无法恰好凑出正容量
    for (int i = 1; i <= n; i++)                         // 依次考虑每一个物品
    {
        for (int j = 1; j <= V; j++)                     // 枚举需要恰好凑出的背包容量
        {
            dp[i][j] = dp[i - 1][j];                      // 不选择第i个物品时继承上一层状态
            if (j >= v[i] && dp[i - 1][j - v[i]] != -1)        // 剩余容量可达时才能选择第i个物品
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]); // 更新恰好装满当前容量的最大价值
        }
    }
    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;   // 若无法恰好装满则输出0，否则输出最大价值
    return 0;                                           // 程序正常结束
}