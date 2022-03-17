# 刷题笔记
1.2.3.4.5.7.
13.15.


## sum相关
目的：在一列数字中查找几个相加等于target的数字，并输出这组数字
例题：
1.twoSum          i+j=target    return {index(i),index(j)}
15.threeSum       i+j+k=0       return {[i1,j1,k1],[i2,j2,k2]} 或 {}

2sum有三种方法：
1. 蛮力法 : for i for j 直到nums[i]+nums[j]=target; 返回 index;           O(n^2);
2. 使用hash map的两次搜索法 : （1）构造map {2:0; 7:1; 11:2; 15:3}           O(n);
                            (2) 若 target-nums[i] 在map的key中，返回 {i,map[key]};
   *注意：在（2）时要排除 i=map[key]的情况。
3. 使用hash map的两次搜索法 : 一边构造map，一边查找target-nums[i]是否在map中。 O(n);
                           排除了i=map[key]的情况。
3sum的两种方法：
1. 蛮力法 : 会超时。      O(n^3);
   去重复:   sort(ret.begin(),ret.end());
            ret.erase(unique(ret.begin(),ret.end()),ret.end()); 
2. 先排序再选择
   (1)使数字有序排列;
   (2)从头选择i; target=0-i;
   (3)二者向内扫描: j+k< target则j++; j+k>target则k--;
   (4)两个优化: 确保跳过重复i; 等于target时,确保跳过重复j或k;

##  subString相关
目的：找到符合条件的子字符串
例题：
3.longest Substring    回文字符串

## median相关
目的：找中间数
例题：
4.寻找两个有序列的中间数

## 转换/加密/解码
13.Roman to Interger     I-1,V-5,X-10; 普通情况叠加即可，小在大前时需要大减小，再叠加；

## 动态规划
91.decode ways           "11106" = 11 10 6 / 1 1 10 6   return 2 (表示有2种解码方式)
f(i)=f(i-1)+f(i-2)     // 但要排除异常情况
// +f(i-1)的条件是：当前数字不是0
// +f(i-2)的条件是：前两个数字不是0X，也不>26。

## 数独 sudoku
九宫格如何数：
i,j -- 行
j,i -- 列
       九宫格:
ii=i*3; ii<i*3+3; ++ii;
   jj=j*3; jj<j*3+3; ++jj;