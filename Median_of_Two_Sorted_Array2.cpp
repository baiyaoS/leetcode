// Median of Two Sorted Array
// 第二个想法：得知中间数的index，再归并排序 --时间O(m+n)  空间O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> median(2,-1);
        int i=0,p1=0,p2=0;
        bool need_2 = (nums1.size() + nums2.size()) % 2 == 0; //偶数need 2, 奇数个just need 1
        int ind = (nums1.size()+nums2.size())/2; 
        for(; i<=ind & p1<nums1.size() & p2<nums2.size(); ++i){
            median[1]=median[0];
            if(nums1[p1]<=nums2[p2]){
                median[0] = nums1[p1++];
            }else{
                median[0] = nums2[p2++];
            }
        }
        for( ; i<=ind & p1<nums1.size(); ++i){
            median[1]=median[0];
            median[0]=nums1[p1++];
        }
        for( ; i<=ind & p2<nums2.size(); ++i){
            median[1]=median[0];
            median[0]=nums2[p2++];
        }
        if(!need_2){
            median[1]=median[0];;
        }
        return 0.5*(median[0]+median[1]);
    }
};


int main(){
    Solution g;
    vector<int> nums1 =  {1,3};
    vector<int> nums2 =  {2};

    // vector<int> nums1 =  {1,2};
    // vector<int> nums2 =  {3,4};

    cout << "The median is " << g.findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}