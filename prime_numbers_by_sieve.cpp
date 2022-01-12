//使用筛法求质数，效率为O(n*log(logn))

#include <vector>
using namespace std;

vector<bool> eratosthenes(int upperbound) {
  vector<bool> flag(upperbound + 1, true);
  flag[0] = flag[1] = false; //exclude 0 and 1
  for (int i = 2; i * i <= upperbound; ++i) {
    if (flag[i]) {
      for (int j = i * i; j <= upperbound; j += i)
        flag[j] = false;
    }
  }	
  return flag;
}