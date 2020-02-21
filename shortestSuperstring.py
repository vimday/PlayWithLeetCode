class Solution(object):
    def shortestSuperstring(self,A):
        n=len(A)
        overlaps=[[0]*n for _ in xrange(n)]
        for i,x in enumerate(A):
            for j,y in enumerate(A):
                if(i!=j):
                    for ans in xrange(min(len(x),len(y)),-1,-1):
                        if(x.endswith(y[:ans])):
                            overlaps[i][j]=ans
                            break
        dp=[[0]*n for _ in xrange(1<<n)]
        parent=[[None]*n for _ in xrange(1<<n)]
        for mask in xrange(1,1<<n):
            for bit in xrange(n):
                if (mask>>bit)&1:
                    pmask=mask^(1<<bit)
                    if(pmask==0): continue
                    for i in xrange(n):
                        if(pmask>>i)&1:
                            value=dp[pmask][i]+overlaps[i][bit]
                            if(value>dp[mask][bit]):
                                dp[mask][bit]=value  
                                parent[mask][bit]=i
        perm=[]
        mask=(1<<n)-1
        seen=[False]*n
        i=max(xrange(n),key=dp[-1].__getitem__)  
        while i is not None:
            seen[i]=True
            perm.append(i)
            mask,i=mask^(1<<i),parent[mask][i]
        perm=perm[::-1]
        perm.extend([i for i in xrange(n) if not seen[i]])
        ans=[A[perm[0]]]
        for i in xrange(1,len(perm)):
            overlap=overlaps[perm[i-1]][perm[i]]
            ans.append(A[perm[i]][overlap:])
        return "".join(ans)
              