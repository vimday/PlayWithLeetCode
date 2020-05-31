#include<bits/stdc++.h>
using namespace std;
// 做完829题过来的，譬如说如果有两个连续的数之和等于target，那么相差为1， (target - 1) % 2 == 0， 且数组一定是从 (target - 1) / 2开始的，数组的元素就是2个；如果是3个连续的数组，那么三个数之间相差为1、2，(target - 1 - 2) % 3 == 0，且数组一定是从 (target - 1 - 2) % 3开始的，数组元素是3个，
// 依次类推，但是注意target必须是大于0的数，且res需要倒序。
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int i=1;
        while(target>0){
            target-=i++;
            if(target>0&&target%i==0){
                vector<int> t;int b=target/i;
                for(int j=0;j<i;j++)
                    t.push_back(b+j);
                res.push_back(t);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//快慢指针
// class Solution {
//     public int[][] findContinuousSequence(int target) {
//         ArrayList<int[]> res = new ArrayList<>();
//         int i = 1;
//         int max = target / 2 + 1;
//         int j = 1;
//         int sum = 1;
//         while (i <= max) {
//             if (sum < target) {
//                 j++;
//                 sum += j;
//             } else if (sum > target) {
//                 sum -= i;
//                 i++;
//             } else {
//                 int[] num = new int[j-i+1];
//                 for (int x = i, y = 0; x <= j; x++, y++) {
//                     num[y] = x;
//                 }
//                 res.add(num);
//                 sum -= i;
//                 i++;
//             }
//         }
//         //这里注意奥，为什么是0，看源码
//         return res.toArray(new int[0][]);
//     }
// }