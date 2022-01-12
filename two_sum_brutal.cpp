// 蛮力法，对于每个i，查找合适的j，直到i+j=target。   -- O(n^2)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(nums[i]+nums[j]==target){
                    return vector<int> {i,j};
                }
            }
        }
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