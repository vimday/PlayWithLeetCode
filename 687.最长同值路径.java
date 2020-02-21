/*
 * @lc app=leetcode.cn id=687 lang=java
 *
 * [687] 最长同值路径
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    int res = 0;

    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return res;
    }

    public int dfs(TreeNode root) {
        if (root == null)
            return 0;
        int l = dfs(root.left);
        int r = dfs(root.right);
        if (root.left != null && root.left.val == root.val) {
            l = l + 1;
        } else
            l = 0;
        if (root.right != null && root.right.val == root.val) {
            r = r + 1;
        } else
            r = 0;
        res = Math.max(res, l + r);
        return Math.max(l, r);
    }

}
// @lc code=end
