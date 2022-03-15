// 组合：1个或者2个
// 有条件的“跨阶梯游戏”

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // 1.特殊情况 - 空字符串返回0；
        if (s.size() == 0) {
            return 0;
        }
        // 2.预处理 - 前两个数字为1，其他都为0
        vector<int> dp(s.size()+1,0);
        dp[0] = 1; // f(0)对于之后的串意味着1种情况
        (s[0] == '0') ? dp[1] = 0 : dp[1] = 1; // 在第一个数字不是0时，f(1)意味着1种情况

        // 3.f(i)=f(i-1)+f(i-2)                // 但要排除异常情况
        for (int i = 2; i <= s.size(); i++) {
            int lastNum = s[i-1] - 48;         // +f(i-1)的条件是：当前数字不是0
            if (lastNum >= 1 && lastNum <= 9) {
                dp[i] += dp[i-1];
            }
            lastNum = stoi(s.substr(i-2, i));  // +f(i-2)的条件是：前两个数字不是0X，也不>26。
            if (lastNum >= 10 && lastNum <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution g;

    // string s="11106";
    string s="111111";

    int ret = g.numDecodings(s);

    cout << ret << endl;
    return 0;
}