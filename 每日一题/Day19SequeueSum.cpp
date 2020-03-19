/*
 * @Author      :vimday
 * @Desc        :给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我我们需要找出长度最小的那个。
 * @Url         :https://www.nowcoder.com/practice/46eb436eb6564a62b9f972160e1699c9?spm=a1z3e1.11874879.0.0.1694723ax3PZJN
 * @File Name   :Day19SequeueSum.cpp
 * @Created Time:2020-03-19 00:38:05
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
int main() {
    int N, L;
    cin >> N >> L;
    for (int i = L; i <= 100; i++) {
        if ((2 * N + i - i * i) % (2 * i) == 0) {
            int start = (2 * N + i - i * i) / (2 * i);
            for (int j = 0; j < i - 1; j++) {
                cout << start + j << " ";
            }
            cout << start + i - 1;
            return 0;
        }
    }
    cout << "No" << endl;
}
