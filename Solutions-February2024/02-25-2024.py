class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.size = [1] * n
        self.count = n

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return
        if self.size[px] < self.size[py]:
            self.par[px] = py
            self.size[py] += self.size[px]
        else:
            self.par[py] = px
            self.size[px] += self.size[py]
        self.count -= 1

class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        uf = UnionFind(len(nums))

        f_index = {}
        for i, n in enumerate(nums):
            factors = set()
            f = 2
            while f * f <= n:
                if n % f == 0:
                    factors.add(f)
                    if f in f_index:
                        uf.union(i, f_index[f])
                    else:
                        f_index[f] = i
                    while n % f == 0:
                        n //= f
                f += 1
            
            if n > 1:
                factors.add(n)
                if n in f_index:
                    uf.union(i, f_index[n])
                else:
                    f_index[n] = i

            for factor in factors:
                uf.union(i, f_index[factor])

        return uf.count == 1
