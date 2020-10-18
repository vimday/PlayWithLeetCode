#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int sz=m+n,i=m-1,j=n-1;
        while(~i&&~j)
            if(A[i]<B[j])
                A[--sz]=B[j--];
            else
                A[--sz]=A[i--];
            
        while(~j)
            A[--sz]=B[j--];
    }
};
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int p1=m-1,p2=n-1,cur=m+n-1;
        while (~p1&&~p2) A[cur--]=A[p1]>B[p2]?A[p1--]:B[p2--];
       // while (~p1) A[cur--]=A[p1--];
        while (~p2) A[cur--]=B[p2--];
    }
};