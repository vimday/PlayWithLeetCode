/*
 * @lc app=leetcode.cn id=214 lang=java
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
    public String shortestPalindrome(String s) {

        if(s.isEmpty()) return s;
        
        //逆序加马拉车常规化
        StringBuilder sb= new StringBuilder("$#");
        for(int i = s.length()-1 ; i>=0 ; i--){
            sb.append(s.charAt(i)+"#");
        }
        sb.append("^");
        
        int[]p = new int[sb.length()];
        int id =1 , right = 1,result = 0;
        for(int i =1 ; i<sb.length()-1;i++){
            if(i < right) p[i] = Math.min(p[2*id - i],right - i);
            else p[i] = 1;
            while( sb.charAt(i+p[i]) == sb.charAt(i-p[i])){
                p[i]++;    
            }
            if(i+p[i] > right){
                right = i + p[i];
                id = i;
            }
            if(i+p[i] == sb.length() -1){
                result = i;
                break;
            }
        }
        
        //把 i的回文串之前的字符串全加到原始字符串中即可
        if(2 >= result - p[result] + 1) return s; //说明本身就是回文串
        return sb.substring(2,result - p[result] + 1).replaceAll("#","") + s;
    }
}
// @lc code=end

