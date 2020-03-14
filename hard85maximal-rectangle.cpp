/*
 * @Author      :vimday
 * @Desc        :lc 85最大矩形 单调非减栈接雨水变种
 * @Url         :https://leetcode-cn.com/problems/maximal-rectangle/
 * @File Name   :hard85maximal-rectangle.cpp
 * @Created Time:2020-03-14 18:20:43
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include<bits/stdc++.h>
using namespace std;
void debug(){
    #ifdef LOCAL
         freopen("E:\\Cpp\\in.txt", "r", stdin);
         freopen("E:\\Cpp\\out.txt", "w", stdout);
    #endif
}
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size();if(m==0) return 0;
        int n=matrix[0].size(),res=0;
        vector<int>dp(n+1);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j)
                dp[j]=matrix[i][j]=='1'?dp[j]+1:0;
            res=max(res,solve(dp));
        }
        return res;
        
    }
    int solve(vector<int> &dp){
        int  res=0;stack<int> s;int n=dp.size();
        //s.push(-1);
        for(int i=0;i<n;++i){
            while(!s.empty()&&dp[i]<dp[s.top()]){
                int h=dp[s.top()];s.pop();
                res=max(res,s.empty()?i*h:(i-s.top()-1)*h);
            }
            s.push(i);
        }
        return res;
    }
};
//位运算法
// if not matrix or not matrix[0]:
//     return 0
// #将每一行看作一个二进制数，然后转化为一个整数
// nums = [int(''.join(row), base=2) for row in matrix]
// ans, N = 0, len(nums)
// #遍历所有行
// for i in range(N):
//     j, num = i, nums[i]
//     #将第i行，连续的，和接下来的所有行，做与运算
//     while j < N:
//         #经过与运算后，num转化为二进制中的1，表示从i到j行，可以组成一个矩形的那几列
//         num = num & nums[j]
//         if not num:
//                 break
//             l, curnum = 0, num
//             #这个循环最精彩
//             #每次循环将curnum和其左移一位的数做与运算
//             #最终的循环次数l表示，最宽的有效宽度，
//             while curnum:
//                 l += 1
//                 curnum = curnum & (curnum << 1)
//             ans = max(ans, l * (j - i + 1))
//             j += 1
//     return ans

// 作者：zhu-meng-10
// 链接：https://leetcode-cn.com/problems/maximal-rectangle/solution/jing-miao-jie-fa-wei-yun-suan-by-zhu-meng-10/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();if(m==0)return 0;
        int n=matrix[0].size();
        int flag[m][n];
        memset(flag,0,sizeof(flag));
      
		//先计算一个flag数组，表示这个位置，同一列向上有多少个连续的1
        for(int i=m-1;i>=0;i--){
			for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    int temp=0;
                    for(int t=i;t>=0;t--){
                        if(matrix[t][j]=='1')temp++; 
                        else if(matrix[t][j]=='0')break;
                    }   
                    flag[i][j]=temp;
                }
            }
        }
        //根据flag数组计算
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(flag[i][j]>0){//如果这里是1
                	int temp=0;
                    //向右找同一行，值不小于本元素的，说明他们可以连在一起
                    for(int t=j;t<n;t++){
                    	if(flag[i][t]>=flag[i][j])temp++;
                    	else break;
	                }
                    //向左找同一行，值不小于本元素的，说明他们可以连在一起
	                for(int t=j;t>=0;t--){
	                    if(flag[i][t]>=flag[i][j])temp++;
	                    else break;
	                }	
	                //temp需要-1，因为向左向右都是从本元素开始的，它被计算了两次
                    res=max(res,flag[i][j]*(temp-1));
				}
                else continue;
            }
        }
        return res;
    }
};


// 作者：CQUhx
// 链接：https://leetcode-cn.com/problems/maximal-rectangle/solution/cyi-dong-fang-fa-by-cquhx/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。