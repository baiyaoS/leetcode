// 罗马数字 2 阿拉伯数字

#include <iostream>
#include <vector>
#include <map> 
using namespace std;

class Solution {
public:

    int romanToInt(string s) {
        map<char, int> Roman = { {'I',1}, {'V',5}, {'X',10}, {'L',50},
                               {'C',100}, {'D',500}, {'M',1000} };
        int ret=0;
        for (int i=0; i<s.size(); ++i){
            char current = s[i];
            char next = (i<s.size()) ? s[i+1] : 'N';
            if ( (next!='N') && (Roman[current] < Roman[next]) ){
                ret += Roman[next] - Roman[current];
                i++;
            } else {
                ret += Roman[current];
            }
        }
        return ret;
    }
};


int main(){
    Solution g;

    // string s = "LVIII"; // 58
    string s = "MCDXXXVII"; // 1437
    // string s = "XCIX"; // 99

    int ret = g.romanToInt(s);

    cout << ret << endl;
    return 0;
}
