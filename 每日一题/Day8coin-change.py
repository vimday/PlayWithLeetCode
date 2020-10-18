# 这道题综合性特别强,可以用背包,深度遍历(dfs),广度遍历(bfs)

# 首先,背包的动态规划,就是取与不取的问题,

# dp[i]表示金额为i需要最少的金额多少,

# 对于任意金额j,dp[j] = min(dp[j],dp[j-coin]+1),如果j-coin存在的话.

# 其次是,深度遍历(dfs),

# 两种方式,一种就是用字典记录深度遍历过程中得到金额i的最小个数

# 一种是,通过判断条件,减少递归次数

# 最后是,广度遍历(bfs),就是每一次从加上所有硬币,因为是广度遍历,所得到一定是可以用最少硬币达到的

# 思路一：动态规划

# 自底向上

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 自底向上
        # dp[i] 表示金额为i需要最少的硬币
        # dp[i] = min(dp[i], dp[i - coins[j]]) j所有硬币
        
        dp = [float("inf")] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            dp[i] = min(dp[i - c] if i - c >= 0 else float("inf") for c in coins ) + 1
        return dp[-1] if dp[-1] != float("inf") else -1
# 自顶向下

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        import functools
        @functools.lru_cache(None)
        def helper(amount):
            if amount == 0:
                return 0
            return min(helper(amount - c) if amount - c >= 0 else float("inf") for c in coins) + 1
        res = helper(amount)
        return res if res != float("inf") else -1
# 思路二：BFS

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        from collections import deque
        queue = deque([amount])
        step = 0
        visited = set()
        while queue:
            n = len(queue)
            for _ in range(n):
                tmp = queue.pop()
                if tmp == 0:
                    return step
                for coin in coins:
                    if tmp >= coin and tmp - coin not in visited:
                        visited.add(tmp - coin)
                        queue.appendleft(tmp - coin)
            step += 1
        return -1
# 思路三：DFS

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort(reverse=True)
        self.res = float("inf")
        
        def dfs(i, num, amount):
            if amount == 0:
                self.res = min(self.res, num)
                return 
            for j in range(i, len(coins)):
                # 剩下的最大值都不够凑出来了
                if (self.res - num) * coins[j] < amount:
                    break
                if coins[j] > amount:
                    continue
                dfs(j, num + 1, amount - coins[j])
                
        for i in range(len(coins)):
            dfs(i, 0, amount)
            
        return self.res if self.res != float("inf") else -1