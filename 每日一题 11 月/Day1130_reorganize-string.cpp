/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1130_reorganize-string.cpp
 * @Created Time:2020-11-30 16:46:43
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
#define forp(i, s, n) for (int i = (s); i < (n); i++)
class Solution {
public:
    string reorganizeString(string S) {
        //记录字母数并降序排列
        vector<pair<char, int>> h(26, make_pair('a', 0));

        for (int i = 0; i < 26; i++)
            h[i].first += i;
        for (char p : S)
            h[p - 'a'].second++;
        sort(h.begin(), h.end(), [](pair<char, int> a, pair<char, int> b) { return a.second > b.second; });

        //判断是否能够重构
        if (h[0].second > (S.size() + 1) / 2)
            return "";

        //答案有size个字符串拼接而成，轮转排入。
        int size = h[0].second;
        vector<string> ans(size);
        int l = 0;

        forp(i, 0, 26) {
            int n = h[i].second;
            forp(j, 0, n) {
                ans[l++ % size].push_back(h[i].first);
            }
        }

        string res;
        forp(i, 0, size) {
            res += ans[i];
        }

        return res;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        /*统计*/
        vector<int> buffer(26, 0);
        for (auto iter : S) ++buffer[(iter - 'a')];

        /*找到最大值*/
        int maxNum = 0, base = -1;
        for (int i = 0; i < 26; ++i) {
            if (maxNum < buffer[i]) {
                maxNum = buffer[i];
                base = i;
            }
        }

        /*边界*/
        if (maxNum > (S.size() + 1) / 2) return "";

        /*将char转为string, 很烦这里*/
        string tmp = "";
        tmp += (base + 'a');
        vector<string> bucket(maxNum, tmp);

        /*分桶统计*/
        int l = 0;
        for (int i = 0; i < 26; ++i) {
            if (i == base) continue;

            for (int j = 0; j < buffer[i]; ++j) {
                bucket[l].push_back(i + 'a');
                /*更新*/
                ++l;
                l %= maxNum;
            }
        }

        /*统计结果*/
        string ans = "";
        for (auto iter : bucket)
            ans += iter;

        return ans;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        if (S.length() < 2) {
            return S;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = S.length();
        for (int i = 0; i < length; i++) {
            char c = S[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        auto cmp = [&](const char& letter1, const char& letter2) {
            return counts[letter1 - 'a'] < counts[letter2 - 'a'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> queue{cmp};
        for (char c = 'a'; c <= 'z'; c++) {
            if (counts[c - 'a'] > 0) {
                queue.push(c);
            }
        }
        string sb = "";
        while (queue.size() > 1) {
            char letter1 = queue.top();
            queue.pop();
            char letter2 = queue.top();
            queue.pop();
            sb += letter1;
            sb += letter2;
            int index1 = letter1 - 'a', index2 = letter2 - 'a';
            counts[index1]--;
            counts[index2]--;
            if (counts[index1] > 0) {
                queue.push(letter1);
            }
            if (counts[index2] > 0) {
                queue.push(letter2);
            }
        }
        if (queue.size() > 0) {
            sb += queue.top();
        }
        return sb;
    }
};
class Solution {
public:
    string reorganizeString(string S) {
        if (S.length() < 2) {
            return S;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = S.length();
        for (int i = 0; i < length; i++) {
            char c = S[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        string reorganizeArray(length, ' ');
        int evenIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) {
                reorganizeArray[oddIndex] = c;
                counts[i]--;
                oddIndex += 2;
            }
            while (counts[i] > 0) {
                reorganizeArray[evenIndex] = c;
                counts[i]--;
                evenIndex += 2;
            }
        }
        return reorganizeArray;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/reorganize-string/solution/zhong-gou-zi-fu-chuan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// /**
//      * 写一个NewChar类，里面包含字母的出现频数，和字母本身。用优先队列PriorityQueue来存储一个一个的NewChar，
//      * 并自己写一个比较器，通过字母的频数降序排列，即构建一个大顶堆。之后两两输出，输出前两个大的，
//      * 然后将它们两个对应的count频率-1，再次放入，继续输出……
//      *
//      * 这样输出是为了总能有一个字母可以把频率最多的字母隔开，优先队列是为了维持储存NewChar的集合总是可以降序输出。
//      *
//      * @param S 定一个字符串S
//      * @return 若可行，输出任意可行的结果。若不可行，返回空字符串。
//      */
//     public String reorganizeString(String S) {
//         //整理好各个字母对应出现的频率
//         int[] counts = new int[26];
//         for (int i = 0; i < S.length(); i++) {
//             counts[S.charAt(i) - 'a']++;
//         }
//         //定义大顶堆规则
//         PriorityQueue<NewChar> pq = new PriorityQueue<>(26, new Comparator<NewChar>() {
//             //重写比较规则 （后面对象 - 前面对象）为大顶堆

//             /**
//              * 拿过来api说
//              * @param o1 the first object to be compared.
//              * @param o2 the second object to be compared.
//              * @return a negative integer, zero, or a positive integer as the
//              *         first argument is less than, equal to, or greater than the
//              *         second.
//              */
//             @Override
//             public int compare(NewChar o1, NewChar o2) {
//                 //基于出现频率的比较
//                 //默认是小顶堆，重写为大顶堆
//                 return o2.count - o1.count;
//             }
//         });
//         //构建大顶堆
//         for (int i = 0; i < 26; i++) {
//             //判断重构是否可行，counts[i] <= (S.length() + 1) / 2)---某个字母过半就不能重构
//             if (counts[i] > 0 && counts[i] <= (S.length() + 1) / 2) {
//                 //可以重构，就往大顶堆里面塞对象
//                 pq.add(new NewChar(counts[i], (char) (i + 'a')));
//             } else if (counts[i] > (S.length() + 1) / 2) {
//                 return "";
//             }
//         }
//         //由大顶堆重构字符串
//         StringBuilder str = new StringBuilder();

//         while (pq.size() > 1) {//最后剩下一个字符或者一个不剩，终止
//             //拿出来频率老大和老二
//             NewChar c1 = pq.poll();
//             NewChar c2 = pq.poll();

//             str.append(c1.letter);
//             str.append(c2.letter);

//             if (--c1.count > 0) pq.add(c1);
//             if (--c2.count > 0) pq.add(c2);
//         }
//         //若剩下一个，特殊处理；一个不剩正好，美滋滋
//         if (pq.size() > 0)
//             str.append(pq.poll().letter);

//         return str.toString();
//     }

//     /**
//      * 自己根据数据特点搞个对象
//      */
//     static class NewChar {
//         int count;//出现的频率
//         char letter;//字母

//         NewChar(int count, char letter) {
//             this.count = count;
//             this.letter = letter;
//         }
//     }

//     /**
//      * 创建PriorityQueue的时候一定要写一个比较器Comparator，因为NewChar是自己写的一个类，
//      * 不写比较器的话程序自己不知道该如何排序，从而会报错：
//      *
//      * cannot be cast to java.lang.Comparable 	at java.util.PriorityQueue.siftUpCom
//      */