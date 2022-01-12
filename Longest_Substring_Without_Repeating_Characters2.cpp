// sliding window 滑动窗口

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};

int main(){
    Solution g;
    string s = "abcabcbb";
    // string s = "bbbbb";
    // string s = "pwwkew";
    cout<<g.lengthOfLongestSubstring(s)<<endl;
}