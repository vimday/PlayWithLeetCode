#include <bits/stdc++.h>
using namespace std;

//超内存
class Solution
{
public:
    string longestDupSubstring(string ss)
    {
        int n = ss.size();
        string res;
        vector<string> sa(n);
        for (int i = 0; i < n; i++)
            sa[i] = ss.substr(i);
        sort(sa.begin(), sa.end());
        for (int i = 1; i < n; i++)
        {
            int sz = min(sa[i].size(), sa[i - 1].size()), j = 0;
            while (j < sz && sa[i - 1][j] == sa[i][j])
                j++;
            if (j > res.size())
                res = sa[i].substr(0, j);
        }
        return res;
    }
};

const int MAXN = 100005;

class Solution
{
public:
    char s[MAXN];
    int sa[MAXN], t[MAXN * 2], t2[MAXN * 2], c[MAXN], n;
    int Rank[MAXN], Height[MAXN];
    int pos = -1, ans;
    void build_sa(int m)
    {
        int i, *x = t, *y = t2;
        for (int i = 0; i < m; i++)
            c[i] = 0;
        for (int i = 0; i < n; i++)
            c[x[i] = s[i]]++;
        for (int i = 1; i < m; i++)
            c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--c[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1)
        {
            int p = 0;
            for (int i = n - k; i < n; i++)
                y[p++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= k)
                    y[p++] = sa[i] - k;
            for (int i = 0; i < m; i++)
                c[i] = 0;
            for (int i = 0; i < n; i++)
                c[x[y[i]]]++;
            for (int i = 1; i < m; i++)
                c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            }
            if (p >= n)
                break;
            m = p;
        }
    }

    void getHeight()
    {
        int i, j, k = 0;
        for (int i = 0; i < n; i++)
            Rank[sa[i]] = i;
        for (int i = 0; i < n; i++)
        {
            if (k)
                k--;
            int j;
            if (Rank[i] - 1 < 0)
                continue;
            j = sa[Rank[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            Height[Rank[i]] = k;
            //    cout << i << ' ' << Height[Rank[i]] << endl;
            if (Height[Rank[i]] > ans)
            {
                ans = Height[Rank[i]];
                pos = i;
            }
        }
    }
    string longestDupSubstring(string S)
    {
        n = S.length();
        for (int i = 0; i < n; i++)
            s[i] = S[i] - 'a';
        build_sa(26);
        getHeight();
        if (pos == -1)
            return "";
        else
        {
            return S.substr(pos, ans);
        }
    }
};

class Solution
{
public:
    const static int maxn = 100005;
    int wa[maxn], wb[maxn], wd[maxn], r[maxn];

    bool isSameStr(int *r, int a, int b, int len)
    {
        return r[a] == r[b] && r[a + len] == r[b + len];
    }

    void doubly(int *r, int *sa, int n, int m)
    {
        int i, j, p;
        int *x = wa, *y = wb, *t; //x表示第一位排序，y表示第二位排序
        for (i = 0; i < m; i++)
        {
            wd[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            wd[x[i] = r[i]]++;
        }
        for (i = 1; i < m; i++)
        {
            wd[i] += wd[i - 1];
        }
        for (i = n - 1; i >= 0; i--)
        {
            sa[--wd[x[i]]] = i;
        }

        for (j = 1, p = 1; p < n; j *= 2, m = p)
        { //j<<1
            // 根据第一位排序得到第二位排序
            for (p = 0, i = n - j; i < n; i++)
            {
                y[p++] = i;
            }
            for (i = 0; i < n; i++)
            {
                if (sa[i] >= j)
                {
                    y[p++] = sa[i] - j;
                }
            }

            for (i = 0; i < m; i++)
            {
                wd[i] = 0;
            }
            for (i = 0; i < n; i++)
            {
                wd[x[i]]++;
            }
            for (i = 1; i < m; i++)
            {
                wd[i] += wd[i - 1];
            }
            for (i = n - 1; i >= 0; i--)
            {
                sa[--wd[x[y[i]]]] = y[i];
            }

            t = x;
            x = y;
            y = t;
            x[sa[0]] = 0;
            p = 1;
            for (i = 1; i < n; i++)
            {
                x[sa[i]] = isSameStr(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
            }
        }
    }
    //能够线性计算height[]的值的关键在于h[](height[rank[]])的性质，即h[i]>=h[i-1]-1，下面具体分析一下这个不等式的由来。
    //论文里面证明的部分一开始看得我云里雾里，后来画了一下终于搞明白了，我们先把要证什么放在这：对于第i个后缀，设j=sa[rank[i] - 1]，
    //也就是说j是i的按排名来的上一个字符串，按定义来i和j的最长公共前缀就是height[rank[i]]，我们现在就是想知道height[rank[i]]至少是多少，而我们要证明的就是至少是height[rank[i-1]]-1。
    //好啦，现在开始证吧。
    //首先我们不妨设第i-1个字符串（这里以及后面指的“第?个字符串”不是按字典序排名来的，是按照首字符在字符串中的位置来的）按字典序排名来的前面的那个字符串是第k个字符串，注意k不一定是i-2，
    //因为第k个字符串是按字典序排名来的i-1前面那个，并不是指在原字符串中位置在i-1前面的那个第i-2个字符串。
    //这时，依据height[]的定义，第k个字符串和第i-1个字符串的公共前缀自然是height[rank[i-1]]，现在先讨论一下第k+1个字符串和第i个字符串的关系。
    //第一种情况，第k个字符串和第i-1个字符串的首字符不同，那么第k+1个字符串的排名既可能在i的前面，也可能在i的后面，但没有关系，因为height[rank[i-1]]就是0了呀，
    //那么无论height[rank[i]]是多少都会有height[rank[i]]>=height[rank[i-1]]-1，也就是h[i]>=h[i-1]-1。
    //第二种情况，第k个字符串和第i-1个字符串的首字符相同，那么由于第k+1个字符串就是第k个字符串去掉首字符得到的，第i个字符串也是第i-1个字符串去掉首字符得到的，
    //那么显然第k+1个字符串要排在第i个字符串前面，要么就产生矛盾了。同时，第k个字符串和第i-1个字符串的最长公共前缀是height[rank[i-1]]，那么自然第k+1个字符串和第i个字符串的最长公共前缀就是height[rank[i-1]]-1。
    //到此为止，第二种情况的证明还没有完，我们可以试想一下，对于比第i个字符串的字典序排名更靠前的那些字符串，谁和第i个字符串的相似度最高（这里说的相似度是指最长公共前缀的长度）？
    //显然是排名紧邻第i个字符串的那个字符串了呀，即sa[rank[i]-1]。也就是说sa[rank[i]]和sa[rank[i]-1]的最长公共前缀至少是height[rank[i-1]]-1，那么就有height[rank[i]]>=height[rank[i-1]]-1，也即h[i]>=h[i-1]-1。
    //证明完这些之后，下面的代码也就比较容易看懂了。

    void calheight(int *r, int *sa, int *height, int *crank, int n)
    {
        int i, j, k = 0, ans;
        for (i = 1; i <= n; i++)
        {
            crank[sa[i]] = i; //计算每个字符串的字典序排名
        }
        for (i = 0; i < n; height[crank[i++]] = k)
        {
            k ? k-- : 0;
            for (j = sa[crank[i] - 1]; r[i + k] == r[j + k]; k++)
                ;
        }
    }

    string longestDupSubstring(string S)
    {
        int sa[maxn], height[maxn], crank[maxn];
        int ans, mlen;
        int i, n = S.length();
        for (i = 0; i < n; i++)
        {
            r[i] = S[i] - 'a' + 1;
        }
        r[n++] = 0;
        doubly(r, sa, n, 27);
        calheight(r, sa, height, crank, n - 1);
        mlen = height[1];
        ans = sa[0];
        for (i = 2; i < n; i++)
        {
            if (mlen < height[i])
            {
                ans = sa[i];
                mlen = height[i];
            }
        }
        return S.substr(ans, mlen);
    }
};

class Solution
{
public:
    class Edge;
    class Node
    {
    public:
        Edge *e;
        int l;
        Node *suffix;
    };

    class Edge
    {
    public:
        int s, l;
        Edge *ne;
        Node *n;
    };

    Node *nodepool;
    Edge *edgepool;
    int nodepoolIdx, edgepoolIdx;

    Node *getNewNode()
    {
        nodepool[nodepoolIdx].e = NULL;
        nodepool[nodepoolIdx].suffix = NULL;
        return &nodepool[nodepoolIdx++];
    }

    Edge *getNewEdge()
    {
        edgepool[edgepoolIdx].n = NULL;
        edgepool[edgepoolIdx].ne = NULL;
        return &edgepool[edgepoolIdx++];
    }

    string longestDupSubstring(string S)
    {
        S.push_back('$');
        nodepoolIdx = edgepoolIdx = 0;
        nodepool = new Node[S.size()];
        edgepool = new Edge[2 * S.size()];

        Node rootbase;
        rootbase.e = NULL;
        rootbase.suffix = &rootbase;
        rootbase.l = 0;

        Node *root = &rootbase;

        Node *currNode = root;
        Node *prevNode = NULL;
        char *currEdgeChar = 0;
        Edge *currEdge = NULL;
        int offset = 0;
        int remainder = 0;

        int maxDupLen = 0;
        int maxIndex = 0;

        for (int i = 0; i < S.size(); ++i)
        {
            ++remainder;
            prevNode = NULL;

            if (!currEdge)
            {
                // 确定当前边（等价于确定首字母）
                currEdgeChar = &S[i];

                // 根据首字母找到边
                for (currEdge = currNode->e;
                     currEdge != NULL && S[currEdge->s] != *currEdgeChar;
                     currEdge = currEdge->ne)
                    ;

                // 初始偏移量 = 0
                offset = 0;
            }
            if (currEdge && S[i] == S[currEdge->s + offset])
            {
                if (offset == currEdge->l - 1)
                {
                    // 行进到下一个点
                    currNode = currEdge->n;
                    currEdge = NULL;
                }
                else
                    ++offset;
            }
            else // 字母不匹配的情况：1) 当前边 + offset != 当前字母;
                 // 2) 当前节点没有 首字母 == 当前字母 的边。
            {
                prevNode = NULL;
                Node *inSertedNode = NULL;
                for (;;)
                {
                    // split 阶段
                    if (currEdge == NULL)
                    {
                        // 无需建立新的节点，只需建立新的边
                        Edge *edge = getNewEdge();
                        edge->s = i;
                        edge->l = S.size() - edge->s;
                        edge->ne = currNode->e;
                        currNode->e = edge;

                        // 只要建立一个新的分支，就需要维护后缀链表
                        if (prevNode != NULL)
                        {
                            prevNode->suffix = currNode;
                        }
                        prevNode = currNode;
                    }
                    else
                    {
                        // 两个节点之间插入一个新的节点，并添加新的边
                        Node *newNode = getNewNode();
                        Edge *edge1 = getNewEdge();
                        Edge *edge2 = getNewEdge();
                        edge1->s = currEdge->s + offset;
                        edge1->l = currEdge->l - offset;
                        edge1->n = currEdge->n;
                        currEdge->l = offset; // s + offset 不属于当前字符串
                        edge2->s = i;
                        edge2->l = S.size() - edge2->s;
                        edge1->ne = edge2;
                        newNode->e = edge1;
                        currEdge->n = newNode;
                        newNode->l = currNode->l + offset;

                        if (newNode->l > maxDupLen)
                        {
                            maxIndex = i - 1;
                            maxDupLen = newNode->l;
                        }

                        // 维护后缀链表：建立（上个节点）指向其后缀（当前节点）的指针
                        if (prevNode != NULL)
                        {
                            prevNode->suffix = newNode;
                        }
                        prevNode = newNode;
                    }

                    if (currNode == root)
                    {
                        // 如果当前节点为根节点，则需要将生长点前移。
                        if (offset == 0)
                            currEdge = NULL;
                        else
                            --offset;
                    }

                    // 处理完成一个后缀
                    --remainder;
                    if (remainder == 0)
                        break;

                    // 顺着后缀链表更新当前点
                    currNode = currNode->suffix;

                    // 如果是在root节点上操作，则需要比较的首字母 = 当前后缀的首字母。
                    if (currNode == root)
                        currEdgeChar = &S[i - remainder + 1];

                    // 根据首字母找到下一个边
                    for (currEdge = currNode->e;
                         currEdge != NULL && S[currEdge->s] != *currEdgeChar;
                         currEdge = currEdge->ne)
                        ;

                    // 考虑 offset > 长度 的情况，沿着树向下搜索，
                    // 找到 “最接近” 当前字符串的点 (在论文中称为 canonize 阶段）
                    while (currEdge && offset >= currEdge->l)
                    {

                        offset -= currEdge->l;
                        currEdgeChar += currEdge->l;
                        currNode = currEdge->n;
                        for (currEdge = currNode->e;
                             currEdge != NULL && S[currEdge->s] != *currEdgeChar;
                             currEdge = currEdge->ne)
                            ;
                    }

                    // 测试当前后缀是否已经包含，则后移生长点，且后面的后缀都不考虑
                    if (currEdge && S[i] == S[currEdge->s + offset])
                    {
                        // 此时建立最后一个后缀链接
                        if (prevNode != NULL)
                            prevNode->suffix = currNode;

                        // 已经包含，则后移生长点，并跳到下一步
                        if (offset == currEdge->l - 1)
                        {
                            // 行进到下一个点
                            currNode = currEdge->n;
                            currEdge = NULL;
                        }
                        else
                            ++offset;

                        break;
                    }
                }
            }
        }

        return S.substr(maxIndex - maxDupLen + 1, maxDupLen);
    }
};

// //也可以二分判断
// class Solution {
//     /*
//     Rabin-Karp with polynomial rolling hash.
//         Search a substring of given length
//         that occurs at least 2 times.
//         Return start position if the substring exits and -1 otherwise.
//         */
//     public int search(int L, int a, long modulus, int n, int[] nums) {
//         // compute the hash of string S[:L]
//         long h = 0;
//         for (int i = 0; i < L; ++i) h = (h * a + nums[i]) % modulus;

//         // already seen hashes of strings of length L
//         HashSet<Long> seen = new HashSet();
//         seen.add(h);
//         // const value to be used often : a**L % modulus
//         long aL = 1;
//         for (int i = 1; i <= L; ++i) aL = (aL * a) % modulus;

//         for (int start = 1; start < n - L + 1; ++start) {
//             // compute rolling hash in O(1) time
//             h = (h * a - nums[start - 1] * aL % modulus + modulus) % modulus;
//             h = (h + nums[start + L - 1]) % modulus;
//             if (seen.contains(h)) return start;
//             seen.add(h);
//         }
//         return -1;
//     }

//     public String longestDupSubstring(String S) {
//         int n = S.length();
//         // convert string to array of integers
//         // to implement constant time slice
//         int[] nums = new int[n];
//         for (int i = 0; i < n; ++i) nums[i] = (int)S.charAt(i) - (int)'a';
//         // base value for the rolling hash function
//         int a = 26;
//         // modulus value for the rolling hash function to avoid overflow
//         long modulus = (long)Math.pow(2, 32);

//         // binary search, L = repeating string length
//         int left = 1, right = n;
//         int L;
//         while (left != right) {
//             L = left + (right - left) / 2;
//             if (search(L, a, modulus, n, nums) != -1) left = L + 1;
//             else right = L;
//         }

//         int start = search(left - 1, a, modulus, n, nums);
//         return start != -1 ? S.substring(start, start + left - 1) : "";
//     }
// }