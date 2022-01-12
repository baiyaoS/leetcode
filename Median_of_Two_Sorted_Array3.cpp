// Median of Two Sorted Array
// 第二个想法：得知中间数的index，再归并排序 --时间O(m+n)  空间O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1[nums1.size()];
    //     for(int i=0; i<nums1.size(); ++i){
    //         n1[i]=nums1[i];
    //     }
    //     int n2[nums2.size()];
    //     for(int i=0; i<nums2.size(); ++i){
    //         n2[i]=nums2[i];
    //     }
    //     return test(n1,n2,nums1.size(),nums2.size());
    // }

    double test(int nums1[], int nums2[], int len1, int len2){
        vector<int> median(2,-1);
        int i=0,p1=0,p2=0;
        bool need_2 = (len1 + len2) % 2 == 0; //偶数need 2, 奇数个just need 1
        int ind = (len1+len2)/2; 
        for(; i<=ind & p1<len1 & p2<len2; ++i){
            median[1]=median[0];
            if(nums1[p1]<=nums2[p2]){
                median[0] = nums1[p1++];
            }else{
                median[0] = nums2[p2++];
            }
        }
        for( ; i<=ind & p1<len1; ++i){
            median[1]=median[0];
            median[0]=nums1[p1++];
        }
        for( ; i<=ind & p2<len2; ++i){
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
    // vector<int> nums1 =  {1,3};
    // vector<int> nums2 =  {2};

    // vector<int> nums1 =  {1,2};
    // vector<int> nums2 =  {3,4};

    // cout << "The median is " << g.findMedianSortedArrays(nums1,nums2) << endl;

    int nums1[]={1,3};
    int nums2[]={2};
    int len1 = 2;
    int len2 = 1;
    cout << "The median is " << g.test(nums1,nums2,len1,len2) << endl;

    return 0;
}