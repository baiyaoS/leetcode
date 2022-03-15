// 输出 x^n，注意：n可能是负数

// 二分法 x^n = x^{n/2} * x^{n/2} * x^{n\%2} 
// 时间复杂度 O(logn)， 空间复杂度 O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / power(x, -n);
        else return power(x, n);
    }
    
private:
    double power(double x, int n) {
        if (n == 0) return 1;
        double v = power(x, n / 2);
        if (n % 2 == 0) return v * v;
        else return v * v * x;
    }
};

int main(){
    Solution g;

    double x = 2.00000;
    int n = 10;

    int ret = g.myPow(x,n);

    cout << ret << endl;
    return 0;
}