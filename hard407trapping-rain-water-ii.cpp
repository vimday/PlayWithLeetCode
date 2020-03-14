/*
 * @Author      :vimday
 * @Desc        :lc 407 接雨水 3d
 * @Url         :https://leetcode-cn.com/problems/trapping-rain-water-ii/
 * @File Name   :hard407trapping-rain-water-ii.cpp
 * @Created Time:2020-03-14 16:25:50
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include<bits/stdc++.h>
using namespace std;
void debug(){
    #ifdef LOCAL
         freopen("E:\\Cpp\\in.txt", "r", stdin);
         freopen("E:\\Cpp\\out.txt", "w", stdout);
    #endif
}

class Solution {
public:
    struct node{
        int x,y,h;
        node(int _x=0,int _y=0,int _h=0):x(_x),y(_y),h(_h){}
        bool operator<(const node& o)const{
            return h > o.h;
        }
    };
    int R,C;
    int trapRainWater(vector<vector<int>>& heightMap) {
        if((R=heightMap.size())<3 || (C=heightMap[0].size())<3) return 0;
        priority_queue<node> Q;
        vector<vector<int>> vis(R,vector<int>(C,0));
        //bottom and up line
        for(int i=0;i<C;++i){
            Q.push(node(0,i,heightMap[0][i]));
            Q.push(node(R-1,i,heightMap[R-1][i]));
            vis[0][i] = vis[R-1][i] = 1;
        }
        
        //left and right line
        for(int i=0;i<R;++i){
            Q.push(node(i,0,heightMap[i][0]));
            Q.push(node(i,C-1,heightMap[i][C-1]));
            vis[i][0] = vis[i][C-1] = 1;
        }
        const int dx[4] = {1,-1,0,0};
        const int dy[4] = {0,0,1,-1};
        int ans = 0;
        while(Q.size()){
            node cur = Q.top();Q.pop();
            const int& x = cur.x;
            const int& y = cur.y;
            for(int i=0;i<4;++i){
                const int nx = x + dx[i];
                const int ny = y + dy[i];
                if(in_grid(nx,ny) && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    int r=max(0,cur.h - heightMap[nx][ny]);
                    ans += r;
                    //(nx,ny)成为新边界的一部分，高度要更新
                    Q.push(node(nx,ny,max(cur.h,heightMap[nx][ny])));
                }
                
            }
        }
        
        return ans;
    }
    
    bool in_grid(int x,int y){
        return x>=0 && x<R && y>=0 && y<C;
    }
};