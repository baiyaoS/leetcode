// 蛮力法  对于每个i、j，查找合适的k，直到i+j+k=0。   -- O(n^3)

#include <iostream>
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
                        return vector<int> {i,j};
                    }
                }
            }
        }
        return ret;
    }
};


                    if (nums[i] + nums[j] + nums[k] == 0) {
                        List < Integer > triplet = new ArrayList < Integer > ();
                        triplet.add(nums[i]);
                        triplet.add(nums[j]);
                        triplet.add(nums[k]);
                        Collections.sort(triplet);
                        result.add(triplet);
                    }
                }
            }
        }
        result = new ArrayList < List < Integer >> (new LinkedHashSet < List < Integer >> (result));
        return result;




int main(){
    Solution g;
    vector<int> nums =  {-1,0,1,2,-1,-4};
    // vector<int> nums =  {0};

    vector<int> ret = g.threeSum(nums);
    cout<<ret[0]<<","<<ret[1]<<endl;
    return 0;
}