// Median of Two Sorted Array
// 第一个想法：先合并成一个数组，再两边求值 --时间O(nlogn)  空间O(n)

// 对于两个sorted array，可以有更加有效率的想法，见Median of Two Sorted Array2.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.assign(nums1.begin(),nums1.end());
        nums.insert(nums.end(),nums2.begin(),nums2.end());
        sort(nums.begin(), nums.end()); // 从小到大
        if(nums.size()%2!=0){
            return nums[nums.size()/2];
        }else{
            return 0.5 * ( nums[nums.size()/2-1] + nums[nums.size()/2] );
        }
    }
};


int main(){
    Solution g;
    // vector<int> nums1 =  {1,3};
    // vector<int> nums2 =  {2};

    vector<int> nums1 =  {1,2};
    vector<int> nums2 =  {3,4};

    cout << "The median is " << g.findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}