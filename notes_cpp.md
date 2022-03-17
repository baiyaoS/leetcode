# c++刷题中常用的操作
部分操作需要支持c++11新特性

## 其他 
auto 是可推断类型

## 头文件
如果要用，记得添加：
#include <iostream>  // cout
#include <algorithm> // sort,  (unique,erase,)
#include <map> //hashmap 字典

## 标准库
1.sort 
*需要两个参数，开始，结尾
*默认 从小到大
sort(vec.begin(),vec.begin()+3);  // vector 排序

2.unique
// 先排序，再删除
sort(ret.begin(),ret.end());
ret.erase(unique(ret.begin(),ret.end()),ret.end()); 
//注意：不使用sort的话，unique也许不会发现重复
//     不使用erase的话，空间还是占有状态，只是把内容放到下表在end()之后的空间了

## vector
1.初始化
vector<int>a(10,0);   // 大小为10，各分量都等于0。

2.赋值
int a[7]={1,2,3,4,5,6,7};
vector<int> b(a,a+7);            //从数组
vector<int> c={1,2,3,4,5,6,7};   //初始值直接赋值
vector<int> d(b);                //从另一个vector

3.添加

## map & set
用于构造哈希表
#include <map>
map<int, int> map;
map<char, int> Roman = { {'I',1}, {'V',5}, {'X',10}, {'L',50},     // 初始化并赋值
                               {'C',100}, {'D',500}, {'M',1000} };
Roman.insert({'I',1});                                             //插入

if (map.find(a)!=map.end()) {                                      //查找key
    return vector<int> { map[a], i };
}

### 遍历set
auto word=col.cbegin();
while (word != col.cend()){
    cout << *word << ',';
    ++word;
}
cout << endl;



## 字符串

数字字符串
头文件都是#include<cstring>
不同点：
①atoi()的参数是 const char* ,因此对于一个字符串str我们必须调用 c_str()的方法把这个string转换成 const char*类型的,
而stoi()的参数是const string*,不需要转化为 const char*；

字符串切片
s.substr(begin, end)

## 二维数组
麻烦死了：
vector<vector<bool>> nine(9, vector<bool>(9));