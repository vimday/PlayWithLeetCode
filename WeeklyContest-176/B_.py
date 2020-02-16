# 提供个不一样的思路，每次算过的数都保存起来，不重复计算

# 1，设置一个字典flag={}用来保存我们算过的乘积，flag[i]=[d,sum]表示第i个位置步长为d的乘积为sum
# 2，每次算完将算过的乘积添加到字典flag
# 3，计算某次前k项积时，从index=len(nums)-k项开始向后遍历，若index在flag中，则直接乘进去，即ans*=flag[index][1],并且更新index+=flag[index][0]

# 参考代码：

class ProductOfNumbers:

    def __init__(self):
        self.nums=[]
        self.l=0
        self.flag={}
        

    def add(self, num: int) -> None:
        self.nums.append(num)
        self.l+=1

    def getProduct(self, k: int) -> int:
        ans=1
        index=self.l-k
       
        while index<self.l:
            if index in self.flag:
                ans*=self.flag[index][1]
                index=index+self.flag[index][0]
            else:
                ans*=self.nums[index]
                index+=1
        
        self.flag[self.l-k]=[k,ans]
        return ans