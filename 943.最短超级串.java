
/*
 * @lc app=leetcode.cn id=943 lang=java
 *
 * [943] 最短超级串
 */
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

// @lc code=start
class Solution {
    public String shortestSuperstring(String[] A) {
        int n=A.length;
        int[][] m=new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) if(i!=j){
                int sz=Math.min(A[i].length(), A[j].length());
                for(int k=sz;k>0;k--) {
                    if(A[i].endsWith(A[j].substring(0,k))){
                        m[i][j]=k;
                        break;
                    }
                }
            }
        int[][] dp=new int[1<<n][n];
        int[][] parent=new int[1<<n][n];
        for(int mask=0;mask<(1<<n);++mask){
            Arrays.fill(parent[mask],-1);
            for(int bit=0;bit<n;++bit)if(((mask>>bit)&1)>0){
                int pmask=mask^(1<<bit);
                if(pmask==0) continue;
                for(int i=0;i<n;++i)if(((pmask>>i)&1)>0){
                    int val=dp[pmask][i]+m[i][bit];
                    if(val>dp[mask][bit]){
                        dp[mask][bit]=val;
                        parent[mask][bit]=i;
                    }
                }

            }
        }
        int[] perm=new int[n];
        boolean[] seen=new boolean[n];
        int t=0;
        int mask=(1<<n)-1;
        int p=0;
        for(int j=0;j<n;j++){
            if(dp[mask][j]>dp[mask][p])
                p=j;
        }
        while(p!=-1){
            perm[t++]=p;
            seen[p]=true;
            int p2=parent[mask][p];
            mask^=1<<p;
            p=p2;
        }
        for(int i=0;i<t/2;++i){
            int v=perm[i];
            perm[i]=perm[t-1-i];
            perm[t-1-i]=v;
        }
        for(int i=0;i<n;i++)
            if(!seen[i])
                perm[t++]=i;
        StringBuilder res=new StringBuilder(A[perm[0]]);
        for(int i=1;i<n;++i)
            res.append(A[perm[i]].substring(m[perm[i-1]][perm[i]]));
        return res.toString();
    }
}
// @lc code=end

class SolutionBT {
    private Map<Integer,String> map = new HashMap<>();
    //用来计算公共部分长度
    public int check(String a, String b){
        for(int start = 0; start < a.length(); start ++){
            if(a.charAt(start) == b.charAt(0)){
                int i = start;
                int j = 0;
                while(i < a.length() && j < b.length() && a.charAt(i) == b.charAt(j)){
                    i ++;
                    j ++;
                }
                if(i == a.length()){
                    return j;
                }
            }
        }
        return 0;
    }
    public String dfs(String[] A, int[][] cop, int used, int cur){
        //把 used | cur << 12 作为状态保存，同时包含当前结点和已经遍历过的结点
        if(map.containsKey(used | cur << 12)){
            return map.get(used | cur << 12);
        }
        String res = A[cur];
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < A.length; i ++){
            if((used & (1 << i)) != 0) continue;
            String tmp = A[cur] + dfs(A,cop,used | 1 << i,i).substring(cop[cur][i]);
            if(tmp.length() < min){
                min = tmp.length();
                res = tmp;
            }
        }
        map.put(used | cur << 12,res);
        return res;
    }
    
    public String shortestSuperstring(String[] A) {
        int n = A.length;
        //先把公共部分长度计算出来
        int[][] cop = new int[n][n];
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                cop[i][j] = check(A[i],A[j]);
            }
        }
        String res = null;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < A.length; i ++){
            String tmp = dfs(A,cop,1 << i,i);
            if(tmp.length() < min){
                min = tmp.length();
                res = tmp;
            }
        }
        return res;
    }
}