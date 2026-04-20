// https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=2021480&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<long long int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + arr[i];

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }

    return 0;
}