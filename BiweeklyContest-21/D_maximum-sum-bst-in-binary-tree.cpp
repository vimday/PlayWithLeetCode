#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//272ms
class Solution {
public:
    unordered_map<TreeNode*,int> m;
    int res=0;
    bool isb(TreeNode* root){
        if(!root) return true;
        if(root->left&&root->left->val>=root->val) return false;
        if(root->right&&root->right->val<=root->val) return false;
        return isb(root->left)&&isb(root->right);
    }
    int gets(TreeNode* root){
        if(!root)
            return 0;
        int rt=root->val+gets(root->left)+gets(root->right);
        if(rt>res)
            res=rt;
        return rt;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        if(m.count(root)){
            if(m[root]>res)
                res=m[root];
            return;
        }
        if(!isb(root)){
            m[root]=-1;
            dfs(root->left);
            dfs(root->right);
        }else{
            m[root]=gets(root);
        }
    }
    int maxSumBST(TreeNode* root) {
        m[nullptr]=0;
        dfs(root);
        return res;
    }
};

//202ms
class Solution {
    bool b[40005];
    int l[40005],r[40005],ma[40005],mi[40005],s[40005],n,ans;
    int work(TreeNode* root)
    {
        if(root==nullptr)return 0;
        int x=++n;
        l[x]=work(root->left);
        r[x]=work(root->right);
        ma[x]=max(root->val,max(ma[l[x]],ma[r[x]]));
        mi[x]=min(root->val,min(mi[l[x]],mi[r[x]]));
        s[x]=root->val+s[l[x]]+s[r[x]];
        b[x]=b[l[x]]&&b[r[x]]&&ma[l[x]]<root->val&&mi[r[x]]>root->val;
        if(b[x])ans=max(ans,s[x]);
        return x;
    }
public:
    int maxSumBST(TreeNode* root) {
        b[0]=1;
        ma[0]=-40000;
        mi[0]=40000;
        n=ans=s[0]=0;
        work(root);
        return ans;
    }
};

//xiaobai2 192ms
class Solution {
public:
    int ret = 0;
    int find(TreeNode* root) {
        int sum = root->val;
        if (!root->left && !root->right) {
            ret = max(ret, root->val);
            return root->val;
        } 
        int _left = 0;
        if (root->left) {
            _left = find(root->left);
        }
        int _right = 0;
        if (root->right) {
            _right = find(root->right);
        }
        if (root->left) {
            if (root->val <= root->left->val) {
                return INT_MIN;
            }
            if (_left == INT_MIN) {
                return INT_MIN;
            }
            sum += _left;
        }
        if (root->right) {
            if (root->val >= root->right->val) {
                return INT_MIN;
            }
            if (_right == INT_MIN) {
                return INT_MIN;
            }
            sum += _right;
        }
        ret = max(ret, sum);
        return sum;
    }
    int maxSumBST(TreeNode* root) {
        ret = 0;
        find(root);
        return ret;
    }
};

//702ms
class Solution {
    int ans = 0;
    unordered_map<TreeNode*, int> sum, lo, hi;
    unordered_map<TreeNode*, bool> good;
    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        sum[root] = root->val;
        lo[root] = root->val;
        hi[root] = root->val;
        good[root] = true;
        if (root->left != nullptr) {
            dfs(root->left);
            if (hi[root->left] >= root->val || !good[root->left])
                good[root] = false;
            sum[root] += sum[root->left];
            hi[root] = max(hi[root], hi[root->left]);
            lo[root] = min(lo[root], lo[root->left]);
        }
        
        if (root->right != nullptr) {
            dfs(root->right);
            if (lo[root->right] <= root->val || !good[root->right])
                good[root] = false;
            sum[root] += sum[root->right];
            hi[root] = max(hi[root], hi[root->right]);
            lo[root] = min(lo[root], lo[root->right]);
        }
        
        if (good[root])
            ans = max(ans, sum[root]);
    }
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        // for (auto p : sum)
        //     cout << p.first << " " << p.second << endl; 
        return ans;
    }
};
//232MS
class Solution {
public:
    // {smallest_num, largest_num, curr_sum} of a tree
    vector<int> traverse(TreeNode* root, int& ans) {
        if (!root) return {INT_MAX, INT_MIN, 0};
        vector<int> left(traverse(root->left, ans)), right(traverse(root->right, ans));
		// check if a tree is BST
        if (left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0]) return {};
		// if BST, update ans
        int curr_sum = left[2] + right[2] + root->val;
        ans = max(ans, curr_sum);
        return {min(left[0], root->val), max(right[1], root->val), curr_sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans(0);
        traverse(root, ans);
        return max(0, ans);
    }
};