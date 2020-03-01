class Solution:
    def rankTeams(self,votes:List[str])->str:
        n=len(votes[0])
        c=[[0]*n for _ in range(26)]
        for vote in votes:
            for i in range(n):
                k=ord(vote[i])-ord('A')
                c[k][i]+=1
        c=sorted([(c[i],-i) for i in range(26) if any(c[i])],reverse=True)
        res=""
        for i in range(len(c)):
            res+=chr(ord('A')-c[i][1])
        return res
