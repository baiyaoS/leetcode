// 目标：对于每个i、j，查找合适的k，将所有i+j+k=0加入ret。   -- O(n^2)

// 如果确定了i和j，那么k早已确定。
// 因此只需两次循环: 1.选取i; 2.让j、k自己从外向内扫完。

// 优化：去除重复的i、k, 可去除所有重复答案

#include <iostream>  // cout
#include <algorithm> // sort unique
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret = {};
        if (nums.size() < 3)
            return ret;
        
        sort(nums.begin(),nums.end());
        
        // 对于每个i，确定j+k=target，从外向内扫描
        for (int i = 0; i < nums.size(); i++) {
            int target = -1 * nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    ret.push_back(triplet);
                    
                    //等于0，则同时向内走，（优化：且跳过所有相同值）
                    while (front < back && nums[front] == triplet[1])
                        front++;
                    while (front < back && nums[back] == triplet[2])
                        back--;
                }
            }
            
            // 优化：若新旧i的值相等，跳过1次
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return ret;
    }
};

int main(){
    Solution g;
    // vector<int> nums =  {-1,0,1,2,-1,-4};
    // vector<int> nums =  {0,0,0};
    vector<int> nums =  {-1,0,1,2,-1,1,0,-4};

    vector<vector<int>> ret = g.threeSum(nums);
    for(int i=0;i<ret.size();++i){
        cout<<ret[i][0]<<","<<ret[i][1]<<","<<ret[i][2]<<endl;
    }
    return 0;
}







