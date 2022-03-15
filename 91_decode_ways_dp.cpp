// 组合：1个或者2个
// 则f(n)=f(n-1)+f(n-2) （需要筛选）

#include <iostream>
#include <vector>
#include <map> 
using namespace std;

class Solution {
public:
    int numDecodings(const string &s) {
        if (s.empty() || s[0] == '0') return 0;
        int prev = 0;
        int cur = 1;
        // 长度为 n 的字符串，有 n+1 个阶梯
        for (size_t i = 1; i <= s.size(); ++i) {
            if (s[i-1] == '0') cur = 0;
            if (i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                prev = 0;
            int tmp = cur;
            cur = prev + cur;
            prev = tmp;
        }
        return cur; 
    }
};

int main(){
    Solution g;

    string s="11106";
    // string s="111111";

    int ret = g.numDecodings(s);

    cout << ret << endl;
    return 0;
}