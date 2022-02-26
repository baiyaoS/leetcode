// 哈希表，两次搜索法
// 第一遍构造哈希函数，第二遍直接查找complement   -- O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public: 
    vector<int> twoSum(vector<int>& nums, int target) {

        // build hashmap
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        // search
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement)!=map.end() && map[complement] != i) {  // 异常情况：互补数=自身
                return vector<int> { i, map[complement] };
            }
        }
        // In case there is no solution
        return vector<int> {-1,-1};
    }
};

int main(){
    Solution g;

    // vector<int> nums={2,7,11,15};
    // int target = 9;

    // vector<int> nums={3,2,4};
    // int target = 6;

    vector<int> nums={3,3};
    int target = 6;

    vector<int> ret = g.twoSum(nums,target);
    cout<<ret[0]<<","<<ret[1]<<endl;

    return 0;
}