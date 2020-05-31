#include<algorithm>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l=dfs(root->left),r=dfs(root->right);
        if(l+r>res)
            res=l+r;
        return max(l,r)+1;
    }
};