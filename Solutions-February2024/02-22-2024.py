class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        outdegree = defaultdict(int)
        indegree = defaultdict(int)

        for a, b in trust:
            outdegree[a]+=1
            indegree[b]+=1

        for i in range(1, n+1):
            if indegree[i] == n-1 and outdegree[i] == 0:
                return i
        
        return -1