/*
 * @Author      :vimday
 * @Desc        :lc day20
 * @Url         :https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/comments/
 * @File Name   :Day20zui-xiao-de-kge-shu-lcof.cpp
 * @Created Time:2020-03-20 00:25:45
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

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        part(arr, 0, n, k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    void part(vector<int>& arr, int l, int r, int k) {
        if (l >= r)
            return;
        swap(arr[l], arr[l + rand() % (r - l)]);
        int t = arr[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[--j] > t)
                ;
            arr[i] = arr[j];
            while (i < j && arr[++i] < t)
                ;
            arr[j] = arr[i];
        }
        arr[i] = t;
        if (i == k)
            return;
        if (i < k)
            part(arr, i + 1, r, k);
        else
            part(arr, l, i, k);
    }
};
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for (int& i : arr) {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while (pq.size()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        help(arr, 0, arr.size() - 1, k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    void help(vector<int>& v, int l, int h, int k) {
        if (l >= h) return;
        int x = v[l], i = l - 1, j = h + 1;
        while (i < j) {
            while (v[++i] < x)
                ;
            while (v[--j] > x)
                ;
            if (i < j)
                swap(v[i], v[j]);
        }
        if (j >= k)
            help(v, l, j, k);
        else
            help(v, j + 1, h, k);
    }
};

// class Solution {
//     public int[] getLeastNumbers(int[] arr, int k) {
//         //return solA(arr, k);
//         quickSort(arr, 0, arr.length - 1, k);
//         return Arrays.copyOf(arr, k);

//     }

//     //单边快排（快速选择算法）
//     //每次剪枝一半的区间，即piviot在k左侧，则左侧不用管了（必然已经是前k个数的一部分）。
//     //在右则，右侧不用管了（必然不在前k数区间）
//     private void quickSort(int[]arr, int l, int r, int k){
//         if(l >= r) return;
//         int i = l - 1, j = r + 1, x = arr[l];
//         while(i < j){
//             while(arr[++i] < x);
//             while(arr[--j] > x);
//             if(i < j){
//                 int t = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = t;
//             }
//         }
//         if(k <= j) quickSort(arr, l, j, k);
//         else quickSort(arr, j + 1, r, k);
//     }

//     //维护大小k的堆  nlogk
//     private int[] solA(int[]arr, int k){
//         PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2)->{
//             return o2 - o1;
//         });
//         for(int i = 0; i < arr.length; i++){
//             if(pq.size() < k) pq.add(arr[i]);
//             else if(pq.size() == k && arr[i] < pq.peek()){
//                 pq.poll();
//                 pq.add(arr[i]);
//             }
//         }
//         Integer[] res = new Integer[k];
//         pq.toArray(res);
//         int[] ans = new int[k];
//         for(int i = 0; i < k; i++) ans[i] = res[i];
//         return ans;
//     }
// }