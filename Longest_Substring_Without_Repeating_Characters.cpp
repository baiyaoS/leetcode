// 蛮力法：对于每一个string，从0开始扫描它的子串
// res保存最长子式的数字；
// 调用checkRepetition返回i-j是否接受为不重复子串   -- O(n2)*O(n) = O(n3)

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        // 很有趣的设计，a~z 26个，A~Z 26个，hmm
        vector<int> chars(128);

        for (int i = start; i <= end; i++) {
            char c = s[i];
            chars[c]++;
            if (chars[c] > 1) {
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution g;
    string s = "abcabcbb";
    // string s = "bbbbb";
    // string s = "pwwkew";
    cout<<g.lengthOfLongestSubstring(s)<<endl;
}