class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj_list = defaultdict(list)
        in_degree = defaultdict(int)
        
        for parent, child in edges:
            adj_list[parent].append(child)
            in_degree[child] += 1

        queue = deque([node for node in range(n) if in_degree[node] == 0])

        res = [set() for _ in range(n)]

        while queue:
            node = queue.popleft()
            for child in adj_list[node]:
                res[child].add(node)
                res[child].update(res[node])  
                in_degree[child] -= 1
                if in_degree[child] == 0:
                    queue.append(child)

        return [sorted(list(ancestors)) for ancestors in res]

