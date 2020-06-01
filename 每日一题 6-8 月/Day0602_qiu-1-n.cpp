/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0602_qiu-1-n.cpp
 * @Created Time:2020-06-02 00:07:29
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
class ConSum  //用构造函数实现
{
public:
    ConSum()  //利用创建n个对象来调n次构造函数
    {
        n++;
        sum += n;
    }
    static int GetSum() {
        return sum;
    }
    static int n;  //用静态数据存储才可达到累加效果
    static int sum;
};

int ConSum::n = 0;  //初始化静态成员
int ConSum::sum = 0;
class Solution {
public:
    int sumNums(int n) {
        ConSum::n = 0;  //初始化静态成员
        ConSum::sum = 0;
        ConSum *a = new ConSum[n];
        return ConSum::GetSum();  //访问静态成员函数必须用域作用符
    }
};

class Solution {
public:
    int res = 0;
    int sumNums(int n) {
        // 1 利用 cpp 静态变量 构造函数
        // 递归
        res += n;
        //n>0?res+=sumNums(n-1):res=0;
        bool f = n > 0 && sumNums(n - 1) > 0;
        return res;
    }
};