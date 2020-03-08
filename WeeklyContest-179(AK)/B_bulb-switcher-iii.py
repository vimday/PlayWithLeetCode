class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        n=len(light)
        a=[False for i in range(n+2)]
        a[0]=True
        cnt=0
        ans=0
        for l in light:
            cnt+=not a[l-1]
            cnt-=a[l+1]
            a[l]=True
            if cnt==0:
                ans+=1
        return ans