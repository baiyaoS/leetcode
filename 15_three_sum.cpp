// 蛮力法  对于每个i、j，查找合适的k，将所有i+j+k=0加入ret。   -- O(n^3)

#include <iostream>  // cout
#include <algorithm> // sort unique
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret = {};
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                for(int k=j+1;k<nums.size();++k){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(),triplet.end());
                        ret.push_back(triplet);
                    }
                }
            }
        }
        // 先排序，再删除
        sort(ret.begin(),ret.end());
        ret.erase(unique(ret.begin(),ret.end()),ret.end());
        // 返回值
        return ret;
    }
};

int main(){
    Solution g;
    vector<int> nums =  {-1,0,1,2,-1,-4};
    // vector<int> nums =  {0};

    vector<vector<int>> ret = g.threeSum(nums);
    for(int i=0;i<ret.size();++i){
        cout<<ret[i][0]<<","<<ret[i][1]<<","<<ret[i][2]<<endl;
    }
    return 0;
}